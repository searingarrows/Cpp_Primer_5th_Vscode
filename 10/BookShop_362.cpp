#include "../include/Sales_item.h"
#include <fstream>
#include <iterator>
int main(int argc, char const* argv[]) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], std::ofstream::out | std::ofstream::app);
	std::istream_iterator<Sales_item> item_itr(input), eof;
	std::ostream_iterator<Sales_item> out_itr(output, "\n");
	Sales_item total = *item_itr++;
	while (item_itr != eof) {
		if (item_itr->same_isbn(total)) {
			total += *item_itr++;
		}
		else {
			*out_itr++ = total;
			total = *item_itr++;
		}
	}
	*out_itr++ = total;
	return 0;
}
