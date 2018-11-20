#include <cstdlib>
#include <iostream>
#include "../include/StrVec.h"
#include "../tool/display.h"

void *operator new(std::size_t size){
    if(void* mem=malloc(size)){
		std::cout << "Alloc: " << size << std::endl;
		return mem;
	}else{
		throw std::bad_alloc();
	}
}
void operator delete(void* mem) noexcept{
	free(mem);
}
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

