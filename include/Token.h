#ifndef TOKEN_H
#define TOKEN_H
#include "Sales_data.h"
#include <string>
class Token {

public:
	Token()
	    : tok(INT)
	    , ival{ 0 } {};
	Token(const Token& t)
	    : tok(t.tok) {
		copyUnion(t);
	}
	Token(Token&& t)
	    : tok(t.tok) {
		copyUnion(std::move(t));
	}
	Token& operator=(const Token&);
	Token& operator=(Token&&);
	~Token() {
		if (tok == STR) {
			sval.~basic_string();
		}
		else if (tok == SD) {
			sdval.~Sales_data();
		}
	}
	Token& operator=(const std::string&);
	Token& operator=(const Sales_data&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	enum { INT, CHAR, DBL, STR, SD } tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};

private:
	
	
	void copyUnion(const Token&);
	// void copyUnion(Token&&);
};

Token& Token::operator=(const Token& t) {
	if (tok == STR && t.tok != STR)
		sval.~basic_string();
	if (tok == SD && t.tok != SD)
		sdval.~Sales_data();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if (tok == SD && t.tok == SD)
		sdval = t.sdval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}
Token& Token::operator=(Token&& t){
	if(this!=&t){
		if (tok == STR && t.tok != STR)
			sval.~basic_string();
		if (tok == SD && t.tok != SD)
			sdval.~Sales_data();
		if (tok == STR && t.tok == STR)
			sval = std::move(t.sval);
		else if (tok == SD && t.tok == SD)
			sdval = std::move(t.sdval);
		else
			copyUnion(t);
		tok = t.tok;
	}
	return *this;
}
Token& Token::operator=(int i) {
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SD) {
		sdval.~Sales_data();
	}
	ival = i;
	tok = INT;
	return *this;
}
Token& Token::operator=(char c) {
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SD) {
		sdval.~Sales_data();
	}
	cval = c;
	tok = CHAR;
	return *this;
}
Token& Token::operator=(double d) {
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SD) {
		sdval.~Sales_data();
	}
	dval = d;
	tok = DBL;
	return *this;
}
Token& Token::operator=(const std::string& s) {
	if (tok == STR)
		sval = s;
	else {
		if (tok == SD) {
			sdval.~Sales_data();
		}
		new (&sval) std::string(s);
	}
	tok = STR;
	return *this;
}
Token& Token::operator=(const Sales_data& s) {
	if (tok == SD)
		sdval = s;
	else {
		if (tok == STR) {
			sval.~basic_string();
		}
		new (&sdval) Sales_data(s);
	}
	tok = SD;
	return *this;
}

void Token::copyUnion(const Token& t) {
	std::cout << "copy union"<<std::endl;
	switch (t.tok) {
	case Token::INT:
		ival = t.ival;
		break;
	case Token::CHAR:
		cval = t.cval;
		break;
	case Token::DBL:
		dval = t.dval;
		break;
	case Token::STR:
		new (&sval) std::string(t.sval);
		break;
	case Token::SD:
		new (&sdval) Sales_data(t.sdval);
		break;
	}
}
// void Token::copyUnion(Token&& t) {
// 	std::cout << "move union" << std::endl;
// 	switch (t.tok) {
// 	case Token::INT:
// 		ival = t.ival;
// 		break;
// 	case Token::CHAR:
// 		cval = t.cval;
// 		break;
// 	case Token::DBL:
// 		dval = t.dval;
// 		break;
// 	case Token::STR:
// 		sval=std::move(t.sval);
// 		break;
// 	case Token::SD:
// 		sdval=std::move(t.sdval);
// 		break;
// 	}
// }

#endif
