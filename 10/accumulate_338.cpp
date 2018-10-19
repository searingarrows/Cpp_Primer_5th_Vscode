#include "../tool/display.h"
#include <iostream>
#include <numeric>
#include <vector>
int main(int argc, char const* argv[]) {
	using namespace std;
	vector<int> vec{ 27, 210, 12, 47, 109, 83 };
	int isum = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << "the sum of: " << DisplaySequentialContainer(vec.cbegin(), vec.cend(), "") << " is " << isum
	          << endl;

	vector<string> v{ "a", "b", "c", "d" };
	string ssum = accumulate(v.cbegin(), v.cend(), string(""));
	cout << "the sum of: " << DisplaySequentialContainer(vec.cbegin(), vec.cend(), "") << " is " << ssum
	          << endl;
	return 0;
}
