#include "../tool/display.h"
#include <algorithm>
#include <iostream>
#include <vector>
int main(int argc, char const* argv[]) {
	using namespace std;
	vector<int> vec{ 27, 210, 12, 47, 109, 83 };
	cout << DisplayContainer(vec.cbegin(), vec.cend()) << endl << "has become: ";
	fill(vec.begin(), vec.end(), 0);
	cout << DisplayContainer(vec.cbegin(), vec.cend(), "") << " after filling with 0"
	          << endl
	          << "and become: ";
	fill_n(vec.begin(), vec.size(), 110);
	cout << DisplayContainer(vec.cbegin(), vec.cend(), "") << " after filling with 110"
	          << endl;
	return 0;
}
