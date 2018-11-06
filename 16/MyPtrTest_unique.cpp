#include "../include/MyPtr/Unique_Pointer.h"
#include <memory>
#include <string>
#include <iostream>
void test(Unique_Pointer<std::string>& ptr){
	std::cout << *ptr << std::endl;
}
int main(int argc, char const *argv[])
{
	auto foo = Unique_Pointer<int>{ new int(42) };
	auto bar(std::move(foo));
	std::cout << *bar << std::endl;

	auto string_ptr = Unique_Pointer<std::string>( new std::string( "Yue" ) );
	test(string_ptr);
	std::cout << string_ptr->size() << std::endl;

	Unique_Pointer<std::string> np(new std::string("Hai"));
	swap(string_ptr, np);
	np = nullptr;
	np = std::move(string_ptr);

	return 0;
};
