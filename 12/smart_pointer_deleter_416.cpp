#include <iostream>
#include <memory>

struct destination {};
struct connection {
	connection() { std::cout << "Constructor!" << std::endl; }
	~connection() {
		std::cout << "Destrutor!" << std::endl;
		std::cout << dest << std::endl;
	}
	destination* dest;
};

connection connect(destination*) {
	std::cout << "Connect!" << std::endl;
	return connection();
}
void disconnect(connection& c){
	c.dest = nullptr;
}
void end_connection(connection* p) {
	disconnect(*p);
}
void f(destination& d) {
	connection c = connect(&d);
}
void f_shared(destination& d) {
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
}

void f_unique(destination& d) {
	connection c = connect(&d);
	std::unique_ptr<connection,decltype(end_connection)*> p(&c, end_connection);
}
int main(int argc, char const* argv[]) {
	destination d;
	f(d);
	std::cout << std::endl;
	f_shared(d);
	std::cout << std::endl;
	f_unique(d);
	return 0;
}
