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

std::string debug_rep(const char* p) {
	return debug_rep(std::string(p));
}

std::string debug_rep(char* p) {
	return debug_rep(std::string(p));
}

std::string debug_rep(const std::string& s) {
	return '"' + s + '"';
}


template<typename T>
std::ostream &print(std::ostream& os,const T &t){
	return os << t;
}

template<typename T,typename... Args>
std::ostream& print(std::ostream& os, const T &t, const Args&... rest){
	os << t << " ";
	print(os, rest...);
	return os;
}

template<typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args&... rest){
	return print(os, debug_rep(rest)...);
}

int main(int argc, char const *argv[])
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow";
	errorMsg(std::cout, i, s, 42);
	return 0;
}
