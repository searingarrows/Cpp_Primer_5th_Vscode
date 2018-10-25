#include <iostream>
#include <string>
using namespace std;

class HasPtr {
	friend int main(int, char const* []);

public:
	HasPtr(const string& s = string())
	    : ps(new string(s))
	    , i(0)
	    , use(new size_t(1)) {}
	~HasPtr();
	HasPtr(const HasPtr& rhs)
	    : ps(rhs.ps)
	    , i(rhs.i)
	    , use(rhs.use) {}
	HasPtr& operator=(const HasPtr& rhs);

private:
	string* ps;
	int i;
	size_t* use;
};
HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

int main(int argc, char const* argv[]) {
	HasPtr* h0 = new HasPtr("Hello");
	//拷贝构造
	HasPtr h1(*h0);
	HasPtr h2 = *h0;
	//拷贝复制
	HasPtr h3;
	h3 = *h0;

	//析构
	delete h0;
	h0 = nullptr;

	cout << *h1.ps << endl << *h2.ps << endl << *h3.ps << endl;
	return 0;
}
