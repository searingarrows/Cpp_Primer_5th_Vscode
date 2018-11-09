#include <iostream>
#include <regex>
#include <vector>
bool valid(const std::smatch& m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

void phone_number() {
	std::regex r;
	try {
		//    1        2      3       4        5       6        7
		// r = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
		r = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}
	std::smatch m;
	std::string fmt("$2.$5.$7");
	std::string s;
	bool valid_record;
	while (std::getline(std::cin,s)) {
		valid_record = false;
		for (std::sregex_iterator it(s.cbegin(), s.cend(), r), end_it; it != end_it; ++it) {
			valid_record = true;
			if (valid(*it)) {
				std::cout << "Valid: " << it->str() << std::endl;
			}
			else {
				std::cout << "invalid: " << it->str() << std::endl;
			}
		}
		
		if (!valid_record) {
			std::cout << "invalid record!!" << std::endl;
		}else{
			std::cout << std::regex_replace(s, r, fmt) << std::endl;
		}
	}
}

int main(int argc, char const* argv[]) {
	phone_number();
	return 0;
}
