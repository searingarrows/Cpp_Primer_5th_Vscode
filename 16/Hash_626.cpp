#include "../include/Sales_data.h"
#include <functional>
#include <unordered_set>


int main(int argc, char const *argv[])
{
	std::unordered_set<Sales_data> SDset;
	Sales_data s;
	SDset.insert(s);
	return 0;
}

