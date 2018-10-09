#include<iostream>
#include <check_type.hpp>
class Foo {};
/**
 * @brief typeid无法判断是否是引用，且会忽略顶层const
 *
 * @return int
 */
int main(){
	// auto i = 0, *p = &i;
	// auto sz = 0, pi = 3.14;
	int i = 0, &r = i;
	auto a = r;
	std::cout << "type name of a is: " << check_type<decltype(a)>() << std::endl;

	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	std::cout << "type name of b is: " << check_type<decltype(b)>() << std::endl;
	std::cout << "type name of c is: " << check_type<decltype(c)>() << std::endl;
	std::cout << "type name of d is: " << check_type<decltype(d)>() << std::endl;
	std::cout << "type name of e is: " << check_type<decltype(e)>() << std::endl;

	const auto f = ci;
	std::cout << "type name of f is: " << check_type<decltype(f)>() << std::endl;

	auto& g = ci;
	// auto& h = 42;
	const auto& j = 42;
	std::cout << "type name of g is: " << check_type<decltype(g)>() << std::endl;
	std::cout << "type name of j is: " << check_type<decltype(j)>() << std::endl;

	auto k = ci, &l = i;
	auto &m = ci, *p = &ci;

	std::cout << "type name of k is: " << check_type<decltype(k)>() << std::endl;
	std::cout << "type name of l is: " << check_type<decltype(l)>() << std::endl;
	std::cout << "type name of m is: " << check_type<decltype(m)>() << std::endl;
	std::cout << "type name of p is: " << check_type<decltype(p)>() << std::endl;
	return 0;
}
