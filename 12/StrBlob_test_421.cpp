#include "../include/StrBlob.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	StrBlob sb{ "hello", "world", "Mooophy" };

	for (auto it = sb.begin(); it!= sb.end();it.incr()){
		std::cout << " " << it.deref();
	}
	std::cout << std::endl;
	return 0;
}
