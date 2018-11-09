#include "../include/Sales_data.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct matches{
	std::vector<Sales_data>::size_type index;
	std::vector<Sales_data>::const_iterator begin;
	std::vector<Sales_data>::const_iterator end;
};
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}
std::vector<matches> findBook(
    const std::vector<std::vector<Sales_data>>& files, const std::string& book) {
	std::vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
		if (found.first != found.second) {
			ret.push_back({it - files.cbegin(), found.first, found.second});
		}
	}
	return ret;
}
void reportResults(
    std::istream& in, std::ostream& os, const std::vector<std::vector<Sales_data>>& files) {
	std::string s;
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			std::cout << s << "not found in any stores" << std::endl;
			continue;
		}
		for (const auto& store : trans) {
			os << "store" << store.index << " sales: "
			   << std::accumulate(store.begin, store.end, Sales_data(s))
			   << std::endl;
		}
	}
}

int main(int argc, char const* argv[]) {
	std::vector<std::vector<Sales_data>> data{ { { "A", 10, 10.0 }, { "B", 15, 5.0 },
		                                           { "C", 20, 8.0 } },
		{ { "A", 15, 10.0 }, { "B", 16, 5.0 }, { "C", 25, 8.0 } },
		{ { "A", 20, 10.0 }, { "B", 5, 5.0 }, { "C", 5, 8.0 } } };
	reportResults(std::cin, std::cout, data);
	return 0;
}