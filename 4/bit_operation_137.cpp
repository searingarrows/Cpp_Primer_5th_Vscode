#include<iostream>
int main()
{
   unsigned long quiz1=0;
   quiz1 |= 1ul << 27;
//    quiz1 &= ~(1ul << 27);
   bool status = quiz1 & (1ul << 27);
   std::cout << "student 27 " << (status ? "passed " : "did not pass ") << "the quiz" << std::endl;
   return 0;
}
