#include "../tool/display.h"
#include <iostream>
#include <iterator>
#include <algorithm>
int main(int argc, char const* argv[]) {
	using namespace std;
	string line("FIRST,MIDDLE,LAST");
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	cout << string(line.crbegin(), rcomma) << endl;
	cout << string(rcomma.base(), line.cend());
	return 0;
}