#include <iostream>

int main()
{
   enum notes
   {
       DO = 1,
       RE = 2,
       MI = 4,
       FA = 8,
       SOL = 16,
       LA = 32,
       TI = 64
   };

   int num = 5;

   int note = 1 << num;
   std::cout << "note " << note << std::endl;

   //std::cout <<

   int state = 0;
   state |= DO;
   state |= MI;
   state |= note;




   if (state & DO) std::cout << "DO" << std::endl;
   if (state & RE) std::cout << "RE" << std::endl;
   if (state & MI) std::cout << "MI" << std::endl;
   if (state & FA) std::cout << "FA" << std::endl;
   if (state & SOL) std::cout << "SOL" << std::endl;
   if (state & LA) std::cout << "LA" << std::endl;
   if (state & TI) std::cout << "TI" << std::endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
