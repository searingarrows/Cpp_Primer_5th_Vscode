#include <iostream>
#include <typeinfo>

// class Base;
// bool operator==(const Base&, const Base&);
class Base {
	friend bool operator==(const Base&, const Base&);

public:
	Base(int _a)
	    : a(_a){};

protected:
	virtual bool equal(const Base& rhs) const { return a == rhs.a; }

private:
	int a;
};
class Derived : public Base {
	friend bool operator==(const Base&, const Base&);

public:
	Derived(int _a, int _b)
	    : Base(_a)
	    , b(_b){};

protected:
	bool equal(const Base& rhs) const {
		auto r = dynamic_cast<const Derived&>(rhs);
		return Base::equal(rhs) && b == r.b;
	}

private:
	int b;
};
bool operator==(const Base& lhs, const Base& rhs) {
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main(int argc, char const* argv[]) {
	Base b0(1), b1(12);
	Derived d0(1, 2), d1(1, 2);
	std::cout << std::boolalpha;
	std::cout << "b0 is equal to b1: " << (b0 == b1) << std::endl;
	std::cout << "d0 is equal to d1: " << (d0 == d1) << std::endl;
	std::cout << "b0 is equal to d0: " << (b0 == d0) << std::endl;
	std::cout << std::noboolalpha;
	return 0;
}
