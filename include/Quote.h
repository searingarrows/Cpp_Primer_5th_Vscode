#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price)
	    : bookNo(book)
	    , price(sales_price) {
		std::cout << "Quote constructing\n";
	}
	Quote(const Quote& q)
	    : bookNo(q.bookNo)
	    , price(q.price) {
		std::cout << "Quote copy constructing\n";
	}
	//移动构造函数应声明为noexcept
	Quote(Quote&& q) noexcept
	    : bookNo(std::move(q.bookNo))
	    , price(std::move(q.price)) {
		std::cout << "Quote move constructing\n";
	}
	Quote& operator=(const Quote& q) {
		bookNo = q.bookNo;
		price = q.price;
		std::cout << "Quote copy assigning\n";
		return *this;
	}
	Quote& operator=(Quote&& q) noexcept {
		bookNo = std::move(q.bookNo);
		price = std::move(q.price);
		std::cout << "Quote move assigning\n";
		return *this;
	}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;
	virtual std::ostream& debug(std::ostream&) const;
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

std::ostream& Quote::debug(std::ostream& os) const {
	os << "ISBN: " << bookNo << ", price: " << price;
	return os;
}

double print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
#endif