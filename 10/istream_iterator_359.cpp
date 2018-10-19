#include <iterator>
#include <iostream>
#include <vector>
#include "../tool/display.h"
int main(int argc, char const *argv[])
{
	using namespace std;
	vector<int> vec;
	istream_iterator<int> int_it(cin);
	istream_iterator<int> eof;
	while(int_it!=eof){
		vec.push_back(*int_it++);
	}
	cout<<DisplaySequentialContainer(vec.cbegin(), vec.cend())<<endl;
	return 0;
}
