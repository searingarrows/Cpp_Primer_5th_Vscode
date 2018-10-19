#include "../tool/display.h"
#include <algorithm>
#include <iostream>

int main(int argc, char const* argv[]) {
	using namespace std;
	int a1[]{ 0, 1, 2, 0, 4, 5, 6, 0, 8, 9 };
	std::replace(std::begin(a1), std::end(a1), 0,42);
	std::cout << DisplaySequentialContainer(std::begin(a1), std::end(a1)) << std::endl;
	return 0;
}