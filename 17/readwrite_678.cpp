#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//输出错误可能是因为换行符导致的，windows为CRLF，linux为LF，mac为CR
int main(int argc, char const* argv[]) {
	using namespace std;
	fstream inOut("../../file/io_test_1.txt", fstream::ate | fstream::in | fstream::out|ios::binary);
	// fstream inOut("C:\\Work\\Cpp\\Cpp_Primer_5th_Vscode\\file\\io_test_1.txt",
	    // fstream::ate | fstream::in | fstream::out);
	if (!inOut) {
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}
	auto end_mark = inOut.tellg();

	inOut.seekg(0, fstream::beg);
	
	while(true){
		string temp;
		auto pre= inOut.tellg();
		if(!getline(inOut, temp)){
			break;
		}
		// remove the '\r' from the new line sequence "\r\n" in CRLF mode on Windows OS
		if(temp.back()=='\r'){
			temp.pop_back();
		}
        cout << temp << "  " << temp.size() << endl;
		auto mark = inOut.tellg();
		// cout << pre << "    ";
		cout << inOut.tellg() <<"    ";
		inOut.seekg(mark);
		cout << inOut.tellg() << endl;
	}
	inOut.seekg(0,fstream::end);
	inOut.clear();

	inOut.seekg(0, fstream::beg);
	// size_t cnt = 0;
	// string line;
	// while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
	// 	cnt += line.size() + 1;
	// 	auto mark = inOut.tellg();
	// 	inOut.seekp(0, fstream::end);
	// 	inOut << cnt;
	// 	if (mark != end_mark)
	// 		inOut << " ";
	// 	inOut.seekg(mark);
	// }
	// inOut.seekp(0, fstream::end);
	// inOut << "\n";
	return 0;
}
