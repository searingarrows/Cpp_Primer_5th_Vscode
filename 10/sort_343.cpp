#include "../tool/display.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isShorter(const string& s1, const string& s2){
	return s1.size() < s2.size();
}
int main(int argc, char const* argv[]) {
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	cout << DisplayContainer(words.cbegin(), words.cend(), "words original:\n")
	          << endl;
	sort(words.begin(), words.end(),isShorter);
	cout << DisplayContainer(words.cbegin(), words.cend(), "words after custom-sort:\n")
	          << endl;
	sort(words.begin(), words.end());
	cout << DisplayContainer(words.cbegin(), words.cend(), "words after default-sort:\n")
	          << endl;
	auto end_unique = unique(words.begin(), words.end());
	cout << DisplayContainer(words.cbegin(), words.cend(), "words after unique:\n")
	          << endl;
	words.erase(end_unique, words.end());
	cout << DisplayContainer(words.cbegin(), words.cend(), "words after erase:\n")
	          << endl;
	stable_sort(words.begin(), words.end(), isShorter);
	cout << DisplayContainer(words.cbegin(), words.cend(), "words after stable-sort:\n")
	          << endl;
	return 0;
}
