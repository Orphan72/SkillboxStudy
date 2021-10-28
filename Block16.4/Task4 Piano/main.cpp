#include <iostream>

int main()
{
   enum notes
   {
       DO = 1,
       RE = 2,
       MI = 3,
       FA = 8,
       SOL = 16,
       LA = 32,
       TI = 64
   };

   int num = 5;
   //std::cout <<

   int state = 0;
   state |= DO;
   state |= MI;
   std::cout << "state1 " << state << std::endl;
   std::cout << "DO " << DO << std::endl;
   std::cout << "state2 " << state << std::endl;
   std::cout << "DO " << DO << std::endl;
   if (state & RE) std::cout << "RE" << std::endl;
   std::cout << "state3 " << state << std::endl;


   if (state & MI) std::cout << "MI" << std::endl;
    std::cout << "state4 " << state << std::endl;
   if (state & FA) std::cout << "FA" << std::endl;
   if (state & SOL) std::cout << "SOL" << std::endl;
   if (state & LA) std::cout << "LA" << std::endl;
   if (state & TI) std::cout << "TI" << std::endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
