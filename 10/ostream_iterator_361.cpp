#include "../tool/display.h"
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc, char const* argv[]) {
	using namespace std;
	vector<int> vec{ 1, 3, 5, 67 };
	ostream_iterator<int> out_it(cout," ");
	for(auto e:vec){
		*out_it++ = e;
		// out_it = e;
	}
	cout << endl;

	copy(vec.cbegin(), vec.cend(), out_it);
	cout << endl;
	return 0;
}