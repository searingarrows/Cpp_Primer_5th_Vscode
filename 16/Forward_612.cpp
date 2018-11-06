#include <iostream>
#include <memory>
#include <utility>

template <typename F, typename T1, typename T2> void flip(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void funcL(int& a, int& b) {
	++a;
	++b;
}

void funcR(int&& a, int&& b) {
	std::allocator<int> alloc;
	int* data = alloc.allocate(2);
	alloc.construct(data, a);
	alloc.construct(data + 1, b);
	std::cout << *data << " " << *(data + 1) << std::endl;
	alloc.destroy(data);
	alloc.destroy(data + 1);
	alloc.deallocate(data, 2);
}

int main(int argc, char const* argv[]) {
	int i0 = 12, i1 = 13;
	// flip([](int&& a, int&& b){
	// 	++a;
	// 	++b;
	// },i0,i1);
	flip(funcL, i0, i1);
	flip(funcR, std::move(i0), std::move(i1));
	std::cout << i0 << " " << i1 << std::endl;
	return 0;
}
