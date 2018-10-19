#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "../tool/display.h"
int main(int argc, char const *argv[])
{
	using namespace std;
	vector<string> sv{ "a", "b", "c", "d" };
	list<const char*> cl{ "a", "b", "c", "d" };

	bool e = equal(sv.cbegin(), sv.cend(), cl.cbegin());
	cout << DisplaySequentialContainer(sv.cbegin(), sv.cend(), "the vector of string: ") << endl
	          << (e ? "is equal to " : "is not equal to ") << endl;
	cout << DisplaySequentialContainer(cl.cbegin(), cl.cend(), "the list of const char*: ") << endl;
	return 0;
}
