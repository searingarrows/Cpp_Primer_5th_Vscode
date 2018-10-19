#include "../tool/display.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

map<string,string> buildMap(ifstream &map_file){
	map<string, string> wordMap;
	string key,value;
	while(map_file>>key&&getline(map_file,value)){
        if(value.size()>1){
			wordMap[key] = value.substr(1);
		}else{
			throw runtime_error("no rule for " + key);
		}
	}
	return wordMap;
}
string transform(string word, map<string,string> &trans_map){
	auto itr = trans_map.find(word);
    if(itr!=trans_map.end()){
        return itr->second;
    }else{
		return word;
	}
}
void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input,text)){
		istringstream iss(text);
		string word;
		bool firstword = true;
        while(iss>>word){
            if(firstword){
                firstword=false;
            }
            else{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[])
{
	
	ifstream file0, file1;
	if(argc>1){
		file0.open(argv[1]);
	}else{
		file0.open("../../file/map_file0.txt");
	}
    if(argc>2){
		file1.open(argv[2]);
	}else{
		file1.open("../../file/map_file1.txt");
	}
	if(!file0.is_open()){
		cerr << "could not open map file!"<<endl;
		return 1;
	}
	if (!file1.is_open()) {
		cerr << "could not open input file!" << endl;
		return 1;
	}
	word_transform(file0, file1);

	return 0;
}
