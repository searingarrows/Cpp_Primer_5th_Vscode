#include "../tool/display.h"
#include <iostream>
#include <iterator>
#include <list>

int main(int argc, char const* argv[]) {
	using namespace std;
	list<int> lst{ 1, 2, 3, 4 };
	list<int> lst2, lst3;
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	cout << DisplayContainer(lst2.cbegin(), lst2.cend()) << endl;
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
	cout << DisplayContainer(lst3.cbegin(), lst3.cend()) << endl;
	return 0;
}
