#include <iostream>
#include <bitset>

int main(int argc, char const *argv[])
{
	bool status;
	std::bitset<30> quizB;
	quizB.set(27);
	status = quizB[27];
	quizB.reset(27);
	std::cout << "student 27 " << (status ? "passed " : "did not pass ") << "the quiz" << std::endl;
	return 0;
}
