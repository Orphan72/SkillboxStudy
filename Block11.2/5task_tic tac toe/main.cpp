#include <iostream>
#include <utility>

char get_elmnt (int x, int y, std::string str1, std::string str2, std::string str3)
{
    //check correct enter x and y
    std::string line = "";
    if (y == 1)
        line = str1;
    else if (y == 2)
        line = str2;
    else
        line = str3;
    return line [x-1];
}


int main() {

   std::string str_first;
   std::string str_secnd;
   std::string str_third;

   std::cout << "Enter the first line\n=>";
   std::getline(std::cin, str_first);

   std::cout << "Enter the second line\n=>";
   std::getline(std::cin, str_secnd);

   std::cout << "Enter the third line\n=>";
   std::getline(std::cin, str_third);

   //запустить в цикле get_elmnt чтобы вывести на экран
  std::cout << "-------------\n";
   for (int yy = 1; yy < 4; yy++)
   {
       for (int xx = 1; xx < 4; xx++)
       {
            std::cout << "| " << get_elmnt (xx, yy, str_first, str_secnd, str_third) << " ";
       }

       std::cout << "|\n";
       std::cout << "-------------\n";
   }

    char element = get_elmnt(3,1,str_first, str_secnd, str_third);

    std::cout << "element: " << element << std::endl;
    int count = 0;
    for (int i = 1; i < 4; i++) {

        if ((get_elmnt(1, i, str_first, str_secnd, str_third) ==
             get_elmnt(2, i, str_first, str_secnd, str_third)) &&
            (get_elmnt(2, i, str_first, str_secnd, str_third) ==
             get_elmnt(3, i, str_first, str_secnd, str_third)))
        {
            count++;
            std::cout << get_elmnt(1, i, str_first, str_secnd, str_third);
            std::cout << "   WIIIIN!!!\n";
            std::cout << count;
        }

    }








    return 0;
}

/*
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры.
Теперь перед вами табличка 3 × 3, которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля.
Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная латинская буква O), пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — то Vanya won,
а иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.
 */