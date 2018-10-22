#include <iostream>
#include <memory>
#include <string>
#include <vector>
int main(int argc, char const* argv[]) {
	using namespace std;
	vector<int> vi{ 1, 3, 5, 7, 9 };
	allocator<int> alloc;
	auto p = alloc.allocate(vi.size() * 2);
	auto q = uninitialized_copy(vi.begin(), vi.end(), p);
	uninitialized_fill_n(q, vi.size(), 42);
	for (auto itr = p, end = p + 2 * vi.size(); itr < end; ++itr) {
		cout << " " << *itr;
	}
	cout << endl;

	unsigned int n = 3;
	string s;
	allocator<string> sa;
	const auto sp = sa.allocate(n);
	auto itr = sp;
	while (itr != sp + n && cin >> s) {
		sa.construct(itr++, s);
	}
	const size_t size = itr - sp;
	auto end = itr;
	for (itr = sp; itr < end; ++itr) {
		cout << " " << *itr;
	}
	cout << endl;
	for (itr = end; itr != sp;) {
		sa.destroy(--itr);
	}
	sa.deallocate(sp, n);

	return 0;
}
