#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double sales_price, std::size_t qty, double disc)
	    : Disc_quote(book, sales_price, qty, disc) {
		std::cout << "Bulk_quote constructing\n";
	}
	Bulk_quote(const Bulk_quote& b)
	    : Disc_quote(b) {
		std::cout << "Bulk_quote copy constructing\n";
	}
	Bulk_quote(Bulk_quote&& b) noexcept
	    : Disc_quote(std::move(b)) {
		std::cout << "Bulk_quote move constructing\n";
	}
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		Disc_quote::operator=(rhs);
		std::cout << "Bulk_quote copy assigning\n";
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		std::cout << "Bulk_quote move assigning\n";
		return *this;
	}
	double net_price(std::size_t) const override;
	Bulk_quote* clone() const& override { return new Bulk_quote(*this); }
	Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }

};

double Bulk_quote::net_price(std::size_t n) const {
	if (n >= quantity) {
		return n * (1 - discount) * price;
	}
	else {
		return n * price;
	}
}

#endif