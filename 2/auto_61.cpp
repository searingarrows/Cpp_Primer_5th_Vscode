#include<iostream>
#include <typecheck.h>
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
	std::cout <<"type name of a is: " << typeid(a).name() << std::endl;

	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	std::cout << "type name of b is: " << typeid(b).name() << std::endl
	<< "type name of c is: " << typeid(c).name() << std::endl
	<< "type name of d is: " << typeid(d).name() << std::endl
	<< "type name of e is: " << typeid(e).name() << std::endl;

	const auto f = ci;
	std::cout << "type name of f is: " << typeid(f).name() << std::endl;

	auto& g = ci;
	// auto& h = 42;
	const auto& j = 42;
	std::cout << "type name of g is: " << typeid(g).name() << std::endl
	          << "type name of j is: " << typeid(j).name() << std::endl;

	auto k = ci, &l = i;
	auto &m = ci, *p = &ci;

	check<decltype(k)>();
	check<decltype(l)>();
	check<decltype(m)>();
	check<decltype(p)>();

	return 0;
}
