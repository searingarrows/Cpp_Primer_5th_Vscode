#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	using namespace std;
	ifstream file("../../file/io_test.txt");
	char sink[50];
    while(file.getline(sink,50)){
		cout << sink << endl;
	}
	cout << file.bad() << "\n--------------------------------------\n"<<endl;

	file.clear();
	file.seekg(0);

	char sink1[60];
	while (file.getline(sink1, 60)) {
		cout << sink1 << endl;
	}
	cout << file.bad() << endl;
	file.close();
	return 0;
}
