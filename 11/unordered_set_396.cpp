#include "../include/Sales_data.h"
#include <unordered_set>
size_t hasher(const Sales_data& sd) {
	return std::hash<std::string>()(sd.isbn());
}
bool eqOp(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() == rhs.isbn();
}
int main(int argc, char const *argv[])
{
	using namespace std;
	using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	SD_multiset bookstore(42, hasher, eqOp);
	return 0;
}
