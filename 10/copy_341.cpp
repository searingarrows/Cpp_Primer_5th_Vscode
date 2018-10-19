#include <iostream>
#include <algorithm>
#include "../tool/display.h"

int main(int argc, char const *argv[])
{
	using namespace std;
	int a1[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);
	cout << DisplayContainer(begin(a2), end(a2)) << endl;
	return 0;
}
