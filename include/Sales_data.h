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
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	friend class std::hash<Sales_data>;

public:
	Sales_data(const std::string& s, unsigned n, double p)
	    : bookNo(s)
	    , units_sold(n)
	    , revenue(p * n) {}
	explicit Sales_data(const std::string& s = "")
	    : Sales_data(s, 0, 0) {}
	explicit Sales_data(istream& is)
	    : Sales_data() {
		read(is, *this);
	};
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }

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

Sales_data& Sales_data::operator+=(const Sales_data& rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

istream& operator>>(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if(is){
		item.revenue = price * item.units_sold;
	}else{
		item = Sales_data();
	}
	
	return is;
}

ostream& print(ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

ostream& operator<<(ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum+=rhs;
	return sum;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs){
	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold
	    && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}

namespace std {
template <> struct hash<Sales_data> {
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator()(const Sales_data& s) const;
};
size_t hash<Sales_data>::operator()(const Sales_data& s) const {
	std::cout << "Hash" << std::endl;
	return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
}
}

#endif