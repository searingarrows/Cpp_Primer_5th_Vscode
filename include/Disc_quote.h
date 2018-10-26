#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
	    : Quote(book, price)
	    , quantity(qty)
	    , discount(disc) {
		std::cout << "Disc_quote constructing\n";
	}
	Disc_quote(const Disc_quote& d)
	    : Quote(d)
	    , quantity(d.quantity)
	    , discount(d.discount) {
		std::cout << "Disc_quote copy constructing\n";
	}
	Disc_quote(Disc_quote&& d) noexcept
	    : Quote(std::move(d))
	    , quantity(std::move(d.quantity))
	    , discount(std::move(d.discount)) {
		std::cout << "Disc_quote move constructing\n";
	}
	Disc_quote& operator=(const Disc_quote& rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		std::cout << "Disc_quote copy assigning\n";
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& rhs) noexcept {
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
		std::cout << "Disc_quote move assigning\n";
		return *this;
	}

	double net_price(std::size_t) const override = 0;
	std::ostream& debug(std::ostream&) const override;

protected:
	std::size_t quantity = 0;
	double discount = 0;
};

std::ostream& Disc_quote::debug(std::ostream& os) const {
	Quote::debug(os);
	os << " minimum discount quantity: " << quantity << ", discount: " << discount;
	return os;
}

#endif