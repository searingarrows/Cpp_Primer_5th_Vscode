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
// Sales_data add(const Sales_data&, const Sales_data&);
// ostream& print(ostream&, const Sales_data&);
// istream& read(istream&, Sales_data&);

// Sales_data::Sales_data(istream &is){
// 	read(is, *this);
// }

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif