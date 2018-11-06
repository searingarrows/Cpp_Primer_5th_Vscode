#include "../include/Blob.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	Blob<int> a{ 1, 3, 5, 7, 9 };
	Blob<int> b{ 2, 4, 6, 8, 10 };
	std::cout << (a == b) << std::endl;
	for (Blob<int>::size_type i = 0; i < a.size(); ++i) {
		std::cout << " " << a[i];
	}
	std::cout << std::endl;

	return 0;
}
