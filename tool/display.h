#include <sstream>
#include <typeinfo>
#if defined(__GNUC__)
#include <cxxabi.h> // abi::__cxa_demangle
#endif
template <typename _It> inline std::string DisplayContainer(_It _beg, _It _end) {
	std::stringstream ss;
	ss << "the container of ";
#if defined(__GNUC__)
	char* real_name = abi::__cxa_demangle(typeid(*_beg).name(), nullptr, nullptr, nullptr);
	ss << real_name;
	free(real_name);
#else
	ss << typeid(*_beg).name();
#endif
	ss << ": (";
	for (auto _it = _beg; _it != _end; ++_it) {
		if (_it != _beg) {
			ss << " ";
		}
		ss << *_it;
	}
	ss << ")";
	return ss.str();
}

template <typename _It>
inline std::string DisplayContainer(_It _beg, _It _end, std::string containerName) {
	std::stringstream ss;
	ss << containerName << "(";
	for (auto _it = _beg; _it != _end; ++_it) {
		if (_it != _beg) {
			ss << " ";
		}
		ss << *_it;
	}
	ss << ")";
	return ss.str();
}