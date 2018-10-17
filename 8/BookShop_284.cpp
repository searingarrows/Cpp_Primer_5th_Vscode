#include "../include/Sales_data.h"
#include <fstream>

int main(int argc, char const* argv[]) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2],std::ofstream::out|std::ofstream::app);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
	return 0;
}
