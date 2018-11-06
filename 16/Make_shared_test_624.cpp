#include "../include/Make_shared.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	auto p = make_shared<std::string>(10, 'c');
	std::cout << *p << std::endl;
	return 0;
}
