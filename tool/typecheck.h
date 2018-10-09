#include <cxxabi.h> // abi::__cxa_demangle
#include <iostream>
#include <typeinfo.h>
template <typename T> struct check {
	check(void) {
#if defined(__GNUC__)
		char* real_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
		std::cout << real_name;
		free(real_name);
#else
		std::cout << typeid(T).name();
#endif 
		}
		~check(void) { std::cout << std::endl; }
	};

#define CHECK_TYPE__(OPT)                                                                          \
	template <typename T> struct check<T OPT> : check<T> {                                         \
		check(void) { std::cout << " " #OPT; }                                                     \
	};

CHECK_TYPE__(const)
CHECK_TYPE__(volatile)
CHECK_TYPE__(const volatile)
CHECK_TYPE__(&)
CHECK_TYPE__(&&)
CHECK_TYPE__(*)