#include "../include/StrVec.h"
#include "../tool/display.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	StrVec vec;
	vec.push_back("a");
	vec.push_back("b");
	vec.push_back("c");
	vec.emplace_back(10, 'd');
	StrVec newVec = vec;
	std::cout << DisplaySequentialContainer(vec.begin(), vec.end(), "vec:") << std::endl;
	std::cout << DisplaySequentialContainer(vec.begin(), vec.end(), "newVec:") << std::endl;
	return 0;
}
