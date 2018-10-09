#include <iostream>
#include <typeinfo>
#if defined(__GNUC__)
#include <cxxabi.h> // abi::__cxa_demangle
#endif

template <typename T> struct TypePrint {
	static std::ostream& Print(std::ostream& os) {
#if defined(__GNUC__)
		char* real_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
		os << real_name;
		free(real_name);
#else
		os << typeid(T).name();
#endif
		return os;
	}
};

#define TYPE_PREFIX(OPT)                                                                           \
	template <typename T> struct TypePrint<T OPT> {                                                \
		static std::ostream& Print(std::ostream& os) {                                             \
			os << #OPT " ";                                                                        \
			return TypePrint<T>::Print(os);                                                        \
		}                                                                                          \
	};
#define TYPE_SUFFIX(OPT)                                                                           \
	template <typename T> struct TypePrint<T OPT> {                                                \
		static std::ostream& Print(std::ostream& os) {                                             \
			TypePrint<T>::Print(os);                                                               \
			os << " " #OPT;                                                                        \
			return os;                                                                             \
		}                                                                                          \
	};
TYPE_PREFIX(const)
TYPE_PREFIX(volatile)
TYPE_PREFIX(const volatile)
TYPE_SUFFIX(&)
TYPE_SUFFIX(&&)
TYPE_SUFFIX(*)

// template <typename T> struct check {
// 	check(void) {
// #if defined(__GNUC__)
// 		char* real_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
// 		std::cout << real_name;
// 		free(real_name);
// #else
// 		std::cout << typeid(T).name();
// #endif
// 	}
// 	~check(void) { std::cout << std::endl; }
// };

// #define CHECK_TYPE__(OPT)                                                                          \
// 	template <typename T> struct check<T OPT> : check<T> {                                         \
// 		check(void) { std::cout << " " #OPT; }                                                     \
// 	};

// CHECK_TYPE__(const)
// CHECK_TYPE__(volatile)
// CHECK_TYPE__(const volatile)
// CHECK_TYPE__(&)
// CHECK_TYPE__(&&)
// CHECK_TYPE__(*)