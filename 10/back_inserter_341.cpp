#include "../tool/display.h"
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc, char const* argv[]) {
	using namespace std;
	vector<int> vec;
	auto it = back_inserter(vec);
	*it = 42;
	cout << DisplaySequentialContainer(vec.cbegin(), vec.cend())<<endl;
	fill_n(back_inserter(vec), 10, 0);
	cout << DisplaySequentialContainer(vec.cbegin(), vec.cend())<<endl;
	return 0;
}
