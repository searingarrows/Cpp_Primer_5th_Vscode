#include <sstream>
#include <typeinfo>
#if defined(__GNUC__)
#include <cxxabi.h> // abi::__cxa_demangle
#endif
template <typename _It> inline std::string DisplaySequentialContainer(_It _beg, _It _end) {
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
			ss << ", ";
		}
		ss << *_it;
	}
	ss << ")";
	return ss.str();
}

template <typename _It>
inline std::string DisplaySequentialContainer(_It _beg, _It _end, std::string containerName) {
	std::stringstream ss;
	ss << containerName << "(";
	for (auto _it = _beg; _it != _end; ++_it) {
		if (_it != _beg) {
			ss << ", ";
		}
		ss << *_it;
	}
	ss << ")";
	return ss.str();
}

template <typename _It> inline std::string DisplayMap(_It _beg, _It _end) {
	std::stringstream ss;
	ss << "the map of ";
#if defined(__GNUC__)
	char* real_name0 = abi::__cxa_demangle(typeid(_beg->first).name(), nullptr, nullptr, nullptr);
	char* real_name1 = abi::__cxa_demangle(typeid(_beg->second).name(), nullptr, nullptr, nullptr);
	ss << real_name0 << " and " << real_name1;
	free(real_name0);
	free(real_name1);
#else
	ss << typeid(_beg->first).name() << " and " << typeid(_beg->second).name();
#endif
	ss << ":\n (";
	for (auto _it = _beg; _it != _end; ++_it) {
		if (_it != _beg) {
			ss << ", ";
		}
		ss << "{"<< _it->first << ", " << _it->second << "}";
	}
	ss << ")";
	return ss.str();
}

template <typename _It>
inline std::string DisplayMap(_It _beg, _It _end, std::string containerName) {
	std::stringstream ss;
	ss << containerName << "(";
	for (auto _it = _beg; _it != _end; ++_it) {
		if (_it != _beg) {
			ss << ", ";
		}
		ss <<"{"<< _it->first<<", "<<_it->second<<"}";
	}
	ss << ")";
	return ss.str();
}