#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
std::size_t VectorCount(std::vector<T>& vec,const T& value){
	return std::count(vec.begin(), vec.end(), value);
}

template<>
std::size_t VectorCount(std::vector<const char*>& vec, const char* const & value){
	return std::count(vec.begin(), vec.end(), value);
}

int main(int argc, char const *argv[])
{
	std::vector<double> dvec{ 1, 2, 3, 4, 5, 4, 4, 3, 2, 1 };
	std::cout << VectorCount(dvec, 4.0) << std::endl;

	std::vector<int> ivec{ 1, 2, 3, 4, 5, 4, 4, 3, 2, 1 };
	std::cout << VectorCount(ivec, 4) << std::endl;

	std::vector<std::string> svec{ "Ding","Ding","Dang" };
	std::cout << VectorCount(svec, std::string("Ding"))<<std::endl;

	std::vector<const char*> cvec{ "Ding", "Ding", "Dang" };
	const char* c = "Ding";
	std::cout << VectorCount(cvec, c) << std::endl;
	return 0;
}
