#include "../include/Bulk_quote.h" 
int main(int argc, char const* argv[]) {
	Bulk_quote q("a", 10.0, 10, 0.5);
	Quote* p = &q;
	q = q;
	q = std::move(q);
	return 0;
}
