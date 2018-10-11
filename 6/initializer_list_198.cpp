#include<iostream>
#include<string>
#include <initializer_list>
void error_msg(std::initializer_list<std::string> il){
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		std::cout << *beg<< " ";
	}
	std::cout << std::endl;
}
void error_msg(int err,std::initializer_list<std::string> il) {
	std::cout << err << ": ";
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}
void error_msg(std::initializer_list<std::string> il,int err) {
	std::cout << err << ": ";
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
	std::string expected("one");
	std::string actual("two");
	if(expected!=actual){
		error_msg({ "functionX", expected, actual });
		error_msg(1,{ "functionX", expected, actual });
		error_msg({ "functionX", expected, actual },1);
	}else{
		error_msg({"functionX","okay"});
		error_msg(0,{ "functionX", "okay" });
		error_msg({ "functionX", "okay" },0);
	}
	actual = "one";
	if (expected != actual) {
		error_msg({ "functionX", expected, actual });
		error_msg(1, { "functionX", expected, actual });
		error_msg({ "functionX", expected, actual }, 1);
	}
	else {
		error_msg({ "functionX", "okay" });
		error_msg(0, { "functionX", "okay" });
		error_msg({ "functionX", "okay" }, 0);
	}
	return 0;
}
