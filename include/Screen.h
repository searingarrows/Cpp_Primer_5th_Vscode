#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
class Screen {
	friend class Window_mgr;

public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c)
	    : height(ht)
	    , width(wd)
	    , contents(ht * wd, c){}
	char get() const { return contents[cursor]; }   //定义在类内的函数隐式inline
	inline char get(pos r, pos c) const;            //显示inline
	Screen& move(pos r, pos c);                     //在Screen.cpp中指定inline
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(ostream& os) { do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const {
		do_display(os);
		return *this;
	}

private:
	void do_display(ostream& os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
inline Screen& Screen::move(pos r, pos c) { //函数定义处指定inline
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const { //在类内部声明成inline
	pos row = r * width;
	return contents[row + c];
}
inline Screen &Screen::set(char c){
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos row, pos col, char ch){
	contents[row * width + col] = ch;
	return *this;
}
#endif