#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	int ch;
    while((ch=cin.get())!=EOF){
		cout.put(ch);
	}
	char c = '\377';
	cout << c << endl;
	return 0;
}
