#include <iostream>
#include <memory>

class DebugDelete {
public:
	DebugDelete(std::ostream& s = std::cerr)
	    : os(s) {}
	template <typename T> void operator()(T* p) const {
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}

private:
	std::ostream& os;
};

int main(int argc, char const *argv[])
{
	double* p = new double;
	DebugDelete d;
	d(p);

	int* ip = new int;
	DebugDelete()(ip);

	std::unique_ptr<int, DebugDelete> uip(new int, DebugDelete());
	std::unique_ptr<std::string, DebugDelete> usp(new std::string, DebugDelete());
	return 0;
}
