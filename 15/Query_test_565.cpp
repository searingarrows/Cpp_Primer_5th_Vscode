#include "../include/Query/Query.h"
#include "../include/Query/NotQuery.h"
#include "../include/Query/AndQuery.h"
#include "../include/Query/OrQuery.h"
#include<fstream>
#include <iostream>

using namespace std;
void runQueries(ifstream& infile) {
	TextQuery tq(infile);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	print(std::cout, q.eval(tq));
	// while (true) {
	// 	cout << "enter word to look for, or q to quit: ";
	// 	string s;
	// 	if (!(cin >> s) || s == "q")
	// 		break;
	// 	print(cout, tq.query(s)) << endl;
	// }
}
int main(int argc, char const* argv[]) {
	ifstream is("../../file/storyDataFile.txt");
	runQueries(is);
	return 0;
}
