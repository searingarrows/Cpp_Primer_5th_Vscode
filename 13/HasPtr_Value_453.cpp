#include <iostream>
#include <string>

class HasPtr {
	friend int main(int, char const* []);
	friend void swap(HasPtr&, HasPtr&);

public:
	HasPtr(const std::string& s = std::string())
	    : ps(new std::string(s))
	    , i(0) {}
	~HasPtr() { delete ps; }
	HasPtr(const HasPtr& rhs)
	    : ps(new std::string(*rhs.ps))
	    , i(rhs.i) {}
	// HasPtr& operator=(const HasPtr& rhs);
	HasPtr& operator=(HasPtr rhs);

private:
	std::string* ps;
	int i;
};
// HasPtr& HasPtr::operator=(const HasPtr& rhs){
// 	auto newp = new std::string(*rhs.ps);
// 	delete ps;
// 	ps = newp;
// 	i = rhs.i;
// 	return *this;
// }

HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main(int argc, char const* argv[]) {
	HasPtr* h0 = new HasPtr("Hello");
	//拷贝构造
	HasPtr h1(*h0);
	HasPtr h2 = *h0;
	swap(h1, h2);
	//拷贝复制
	HasPtr h3;
	h3 = *h0;

	//析构
	delete h0;
	h0 = nullptr;

	std::cout << *h1.ps << std::endl << *h2.ps << std::endl << *h3.ps << std::endl;
	return 0;
}
