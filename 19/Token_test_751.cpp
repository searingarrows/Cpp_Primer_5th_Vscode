#include "../include/Token.h"

int main(int argc, char const *argv[])
{
	Token t1, t2,t3;
	t1 = std::string("A");
	t2 = std::string("B");
	t3 = Sales_data("ABC",5,10.0);
	std::cout << t1.sval << " " << t2.sval << std::endl;
	t1 = t2;
	std::cout << t1.sval << " " << t2.sval << std::endl;
	t1 = std::move(t3);
	std::cout << t1.sval << " " << t3.sval << std::endl;
	return 0;
}
