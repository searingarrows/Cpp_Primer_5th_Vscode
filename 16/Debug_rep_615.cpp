#include <iostream>
#include <sstream>
template <typename T> std::string debug_rep(const T& t) {
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> std::string debug_rep(T* p) {
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p) {
		ret << " " << debug_rep(*p);
	}
	else {
		ret << " null pointer";
	}
	return ret.str();
}
//必须有这句声明，否则将调用debug_rep(const T&)的string版本
std::string debug_rep(const std::string&);
template<>
std::string debug_rep(char* c){
	return debug_rep(std::string(c));
}

template <> 
std::string debug_rep(const char* c) {
	return debug_rep(std::string(c));
}


// std::string debug_rep(const char* p) {
// 	return debug_rep(std::string(p));
// }

// std::string debug_rep(char* p) {
// 	return debug_rep(std::string(p));
// }

std::string debug_rep(const std::string& s) {
	return '"' + s + '"';
}

int main(int argc, char const *argv[])
{
	std::string s("hi");
	std::cout << debug_rep("hi world") << std::endl;
	return 0;
}
