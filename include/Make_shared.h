#ifndef MAKE_SHARED_H
#define MAKE_SHARED_H

#include <memory>

template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args&&... args){
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif