#include "../tool/display.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void elimDups(vector<string> &words){
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz){
	elimDups(words);
	stable_sort(words.begin(), words.end(),
	    [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
	auto wc
	    = find_if(words.begin(), words.end(), [=](const string& s) { return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << (count>1?"words":"word") << " of length " << sz
	          << " or longer" << endl;
	for_each(wc, words.end(), [](const string& s) { cout << s << " "; });
	cout << endl;
}
int main(int argc, char const* argv[]) {
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow",
		"red", "turtle" };
	cout << DisplayContainer(words.cbegin(), words.cend(), "words original:\n")
	          << endl;
	biggies(words, 4);
	
	return 0;
}