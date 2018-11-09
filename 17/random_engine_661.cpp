#include <random>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::uniform_int_distribution<unsigned> u(0, 9);
	std::default_random_engine e;
	for (std::size_t i = 0; i < 10;++i){
		std::cout << u(e) << " ";
	}
		return 0;
}
