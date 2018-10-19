#include <algorithm>
#include <iostream>
int main(int argc, char const *argv[])
{
	using namespace std;
	int ia[]{ 27, 210, 12, 47, 109, 83 };
	int val = 83;
	int* result = std::find(std::begin(ia), std::end(ia), val);
	std::cout << val << " is" << (result == std::end(ia) ? " not" : "") << " present!" << std::endl;
	return 0;
}
