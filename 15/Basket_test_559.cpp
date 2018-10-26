#include "../include/Bulk_quote.h"
#include "../include/Basket.h"

int main(int argc, char const *argv[])
{
	Basket basket;
	Quote quote("A", 10.0);
	basket.add_item(std::move(quote));
	basket.add_item(Bulk_quote("B", 15.0, 2, 0.5));
	basket.add_item(Bulk_quote("B", 15.0, 2, 0.5));
	basket.add_item(Bulk_quote("B", 15.0, 2, 0.5));
	basket.total_receipt(std::cout);
	return 0;
}
