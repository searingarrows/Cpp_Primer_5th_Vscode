#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);

public:
	
	Sales_data(const std::string& s, unsigned n, double p)
	    : bookNo(s)
	    , units_sold(n)
	    , revenue(p * n) {}
	explicit Sales_data(const std::string& s = "")
	    : Sales_data(s, 0, 0){}
	explicit Sales_data(istream& is):Sales_data(){
		read(is, *this);
	};
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);

#endif