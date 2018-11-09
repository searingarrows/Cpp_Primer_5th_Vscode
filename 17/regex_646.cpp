#include <iostream>
#include <regex>

void ei() {
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	std::smatch results;
	std::string test_str = "receipt freind theif receive";
	if (std::regex_search(test_str, results, r))
		std::cout << "the result of \"ei\" is: " << results.str() << std::endl;
}

void cpp() {
	std::regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
	std::smatch results;
	std::string filename;
	while (std::cin >> filename) {
		if (std::regex_search(filename, results, r)) {
			std::cout << results.str() << std::endl;
		}
	}
}

void error() {
	std::string reg;
	while (std::cin >> reg) {
		try {
			std::regex(reg, std::regex::icase);
		}
		catch (std::regex_error e) {
			std::cout << e.what() << "\ncode: " << e.code() << std::endl;
		}
	}
}

void ei_multi() {
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::smatch results;
	std::string test_str = "receipt freind theif receive";
	for (std::sregex_iterator it(test_str.cbegin(), test_str.cend(), r), end_it; it != end_it;
	     ++it) {
		std::cout << it->str() << std::endl;
	}
}

void ei_multi_sub() {
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::smatch results;
	std::string test_str = "receipt freind theif theif receive";
	for (std::sregex_iterator it(test_str.cbegin(), test_str.cend(), r), end_it; it != end_it;
	     ++it) {
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		std::cout << it->prefix().str().substr(pos) << "\n\t\t>>> " << it->str() << " <<<\n"
		          << it->suffix().str().substr(0, 40) << std::endl;
	}
}

void cpp_sub() {
	std::regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", std::regex::icase);
	std::smatch results;
	std::string filename;
	while (std::cin >> filename) {
		if (std::regex_search(filename, results, r)) {
			std::cout << results.str(1) << std::endl;
		}
	}
}

int main(int argc, char const* argv[]) {
	// ei();
	// cpp();
	// error();
	// ei_multi();
	// ei_multi_sub();
	// cpp_sub();
	return 0;
}
