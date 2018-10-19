#include <iostream>
using namespace std;
void fcn1(){
	size_t v1 = 42;
	auto f = [v1] { return v1; };
	v1 = 0;
	cout<<"capture by value: " << f() << endl;
}

void fcn2() {
	size_t v1 = 42;
	auto f = [&v1] { return v1; };
	v1 = 0;
	cout << "capture by reference: " << f() << endl;
}

void fcn3() {
	size_t v1 = 42;
	auto f = [v1]()mutable { return ++v1; };
	v1 = 0;
	cout << "capture by value (mutable): " << f() << endl;
}

void fcn4(){
	size_t v1 = 42;
	auto f = [&v1]() { return ++v1; };
	v1 = 0;
	cout << "capture by reference (++): " << f() << endl;
}
int main(int argc, char const *argv[])
{
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	return 0;
}
