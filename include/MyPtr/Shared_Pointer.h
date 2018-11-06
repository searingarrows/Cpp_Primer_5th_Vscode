#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include <functional>

struct deleteT {
	template <typename T> void operator()(T* t) const { delete t; }
};

template <typename T> class Shared_Pointer;
template <typename T> void swap(Shared_Pointer<T>& lhs, Shared_Pointer<T>& rhs) {
	using std::swap;
	swap(lhs.use, rhs.use);
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.deleter, rhs.deleter);
}

template <typename T> class Shared_Pointer {
	friend void swap<T>(Shared_Pointer<T>& lhs, Shared_Pointer<T>& rhs);
public:
	typedef T element_type;
	Shared_Pointer()
	    : use(new std::size_t(1))
	    , ptr(nullptr)
	    , deleter(deleteT()) {}
	explicit Shared_Pointer(T* t)
	    : use(new std::size_t(1))
	    , ptr(t)
	    , deleter(deleteT()) {}
	Shared_Pointer(const Shared_Pointer& rhs)
	    : use(rhs.use)
	    , ptr(rhs.ptr)
	    , deleter(rhs.deleter) {
		++*use;
	}
	Shared_Pointer(Shared_Pointer&& rhs) noexcept
	    : use(rhs.use)
	    , ptr(rhs.ptr)
	    , deleter(std::move(rhs.deleter)) {
		rhs.ptr = nullptr;
		rhs.use = nullptr;
	}
	//交换并拷贝，同时作用于拷贝赋值运算符和移动赋值运算符
	Shared_Pointer& operator=(Shared_Pointer rhs) {
		swap(rhs);
		return *this;
	}
	explicit operator bool() const { return ptr ? true : false; }
	T& operator*() const { return *ptr; }
	T* operator->() const { return &*ptr; }
	//交换后use可能为nullptr
	std::size_t use_count() const { return use ? *use : 0; }
	// this是否为const不影响T*的const
	T* get() const { return ptr; }
	bool unique() const { return *use == 1; }
	void swap(Shared_Pointer& rhs) { ::swap(*this, rhs); }
	void reset() { decrement_and_destroy(); }
	void reset(T* t) {
		if (t != ptr) {
			decrement_and_destroy();
			ptr = t;
			use = new std::size_t(1);
		}
	}
	void reset(T* t, const std::function<void(T*)>& d) {
		reset(t);
		deleter = d;
	}
	~Shared_Pointer() { decrement_and_destroy(); }

private:
	std::size_t* use;
	T* ptr;
	std::function<void(T*)> deleter;
	void decrement_and_destroy() {
		if (ptr && --*use == 0) {
			delete use;
			deleter(ptr);
		}
		else if (!ptr) {
			delete use;
		}
		use = nullptr;
		ptr = nullptr;
	}
};

#endif