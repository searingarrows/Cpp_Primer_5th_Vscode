#include "../include/MyPtr/Shared_Pointer.h"
#include <memory>
#include <string>
#include <iostream>
void test(Shared_Pointer<std::string> ptr){
	std::cout << *ptr << std::endl;
}
int main(int argc, char const *argv[])
{
	auto foo = Shared_Pointer<int>{ new int(42) };
	auto bar(foo);
	std::cout << *foo << std::endl;
	std::cout << foo.use_count() << std::endl;

	auto string_ptr = Shared_Pointer<std::string>{ new std::string{ "Yue" } };
	test(string_ptr);
	std::cout << string_ptr->size() << std::endl;

	Shared_Pointer<std::string> np(std::move(string_ptr));
	swap(foo, bar);
	foo = std::move(bar);
	return 0;
};
