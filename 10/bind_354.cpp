#include "../tool/display.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}
bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}
void print(ostream& os, const string& s, char c) {
	os << s << c;
}
void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggies(vector<string>& words, vector<string>::size_type sz) {
	using namespace placeholders;
	elimDups(words);
	stable_sort(words.begin(), words.end(), bind(isShorter, _1, _2));
	auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = words.end() - wc;
	cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz
	          << " or longer" << endl;
	for_each(wc, words.end(), bind(print, ref(cout), _1, ' '));
	cout << endl;
}
int main(int argc, char const* argv[]) {
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow",
		"red", "turtle" };
	cout << DisplaySequentialContainer(words.cbegin(), words.cend(), "words original:\n") << endl;
	biggies(words, 4);

	return 0;
}