#include<iostream>
int main(){
	int i = 42;
	float f = 42.f;
	const int &ri = i, &rf=f;
	std::cout << "ri is: " << ri << ", rf is: " << rf << std::endl;
	i = 52;
	f = 52.f;
	std::cout << "ri is: " << ri << ", rf is: " << rf << std::endl;
	return 0;
}