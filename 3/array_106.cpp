#include<iostream>
#include <iterator>
#include<check_type.hpp>
int main(){
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, -7, 8, 9 };
	std::cout << "the array elements are as below: " << std::endl;
	for (auto b = arr, e = &arr[10]; b != e; ++b) {
		std::cout << *b<<" ";
	}
	std::cout << std::endl;
	auto b = std::begin(arr);
	auto e = std::end(arr);
	while(b!=e&&*b>=0){
		++b;
	}
    if(b!=e){
		std::cout << "the first negative number is:" << *b<<std::endl;
	}else{
		std::cout << "there is no negative number" << *b<<std::endl;
	}
	std::cout<<"The type of result of (b-e) is : " << check_type<decltype(b - e)>() << std::endl;
	auto arr4 = &arr[4];
	std::cout << "The element at position 4 is: " << arr4[0] << ", " << std::endl
	          << "and the element before it is: " << arr4[-1] << std::endl;
	return 0;
}