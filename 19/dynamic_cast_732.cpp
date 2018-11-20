#include <iostream>

class A {
public:
	A(){};
	virtual ~A(){};
};
class B : virtual public A {
public:
	B(){};
	virtual ~B(){};
};
class C : virtual public B {
public:
	C(){};
	virtual ~C(){};
};
class D : public B, public A {
public:
	D(){};
	virtual ~D(){};
};

void a() {
	A* pa = new C;
	B* pb = dynamic_cast<B*>(pa);
	std::cout << "a: " << (pa != 0) << std::endl;
}
void b() {
	B* pb = new B;
	C* pc = dynamic_cast<C*>(pb);
	std::cout << "b: " << (pc != 0) << std::endl;
}
// void c() {
// 	A* pa = new D;
// 	B* pb = dynamic_cast<B*>(pa);
// }
int main(int argc, char const* argv[]) {
	std::cout << std::boolalpha;
	a();
	b();
	// c();
	std::cout << std::noboolalpha;
	return 0;
}
