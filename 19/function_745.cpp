#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "../include/Sales_data.h"
#include <fstream>

int VecCount0(const std::vector<std::string>& vec){
	return std::count_if(
	    vec.begin(), vec.end(), std::function<bool(const std::string&)>(&std::string::empty));
}
int VecCount1(const std::vector<std::string>& vec) {
	return std::count_if(
	    vec.begin(), vec.end(), std::mem_fn(&std::string::empty));
}
int VecCount2(const std::vector<std::string>& vec) {
	return std::count_if(vec.begin(), vec.end(), std::bind(&std::string::empty,std::placeholders::_1));
}
int VecCount3(const std::vector<std::string>& vec) {
	return std::count_if(vec.begin(), vec.end(), [](const std::string& s) { return s.empty(); });
}
Sales_data& SalesDataCheck(std::vector<Sales_data>& vec, double price){
	return *std::find_if(
	    vec.begin(), vec.end(), [price](Sales_data& s) { return s.avg_price() > price; });
}

int main(){
	std::vector<std::string> vec{ "a", "b", "", "d", "" };
	std::cout << "the number of empty string is: " << VecCount0(vec) << std::endl;
	std::cout << "the number of empty string is: " << VecCount1(vec) << std::endl;
	std::cout << "the number of empty string is: " << VecCount2(vec) << std::endl;
	std::cout << "the number of empty string is: " << VecCount3(vec) << std::endl;

	std::ifstream file("../../file/bookshop_in.txt");
	std::vector<Sales_data> svec;
	Sales_data data;
	while(file>>data){
		svec.push_back(data);
	}
	auto s = SalesDataCheck(svec, 80.0);
	std::cout << "first book with higher price than 80 is: " << s.isbn() << std::endl;
}