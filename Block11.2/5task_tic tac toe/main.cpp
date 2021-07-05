#include <iostream>
#include <utility>

char get_elmnt (int x, int y, std::string str1, std::string str2, std::string str3)
{
    std::string line = "";
    if (y == 1)
        line = str1;
    else if (y == 2)
        line = str2;
    else
        line = str3;
    return line [x-1];
}

int get_count (char ch, std::string str1, std::string str2, std::string str3) {
    int count = 0;
    for (int y = 1; y < 4; y++) {
        for (int x = 1; x < 4; x++) {
            std::cout << "| " << get_elmnt (x, y, str1, str2, str3) << " ";
            if (get_elmnt (x, y, str1, str2, str3) == ch) count++;
        }
        std::cout << "|\n";
        std::cout << "-------------\n";
    }
    return count;
}

bool check_correct_symbol (std::string str) {
    if (str.length() > 3)
        return false;
    else {
        for (int i = 0; i < 3; i++) {
            if (str [i] != '.' && str [i] != 'O' && str [i] != 'X')
                return false;
        }
    }
    return true;
}

char get_win (std::string str1, std::string str2, std::string str3) {
    char element = '-';
    int countWin = 0;
    for (int i = 1; i < 4; i++) {
        if ((get_elmnt(1, i, str1, str2, str3) ==
             get_elmnt(2, i, str1, str2, str3)) &&
            (get_elmnt(2, i, str1, str2, str3) ==
             get_elmnt(3, i, str1, str2, str3)))
        {
            element = get_elmnt(1, i, str1, str2, str3);
            countWin++;
        }

        else if ((get_elmnt(i, 1, str1, str2, str3) ==
                  get_elmnt(i, 2, str1, str2, str3)) &&
                 (get_elmnt(i, 2, str1, str2, str3) ==
                  get_elmnt(i, 3, str1, str2, str3)))
        {
            element = get_elmnt(i, 1, str1, str2, str3);
            countWin++;
        }

        std::cout << "countWin " << countWin << std::endl;

    }

    if ((get_elmnt(1, 1, str1, str2, str3) ==
         get_elmnt(2, 2, str1, str2, str3)) &&
        (get_elmnt(2, 2, str1, str2, str3) ==
         get_elmnt(3, 3, str1, str2, str3)))
    {
        element = get_elmnt(1, 1, str1, str2, str3);
        countWin++;
    }

    else if ((get_elmnt(3, 1, str1, str2, str3) ==
              get_elmnt(2, 2, str1, str2, str3)) &&
             (get_elmnt(2, 2, str1, str2, str3) ==
              get_elmnt(1, 3, str1, str2, str3)))
    {
        element = get_elmnt(3, 1, str1, str2, str3);
        countWin++;
    }

    if (countWin > 1) return 'N';

    return element;
}

bool check_correct_game (std::string str1, std::string str2, std::string str3) {

        if (get_win (str1, str2, str3) == 'N')
            return false;

        else if (get_count ('O', str1, str2, str3) >
             get_count ('X', str1, str2, str3))
            return false;

         else if (get_win (str1, str2, str3) == 'X' &&
                 (get_count ('O', str1, str2, str3) ==
                  get_count ('X', str1, str2, str3)))
             return false;
         else if (get_win (str1, str2, str3) == 'O' &&
                 (get_count ('X', str1, str2, str3) >
                  get_count ('O', str1, str2, str3)))
             return false;

         else return true;
}



int main() {

   std::string str_first;
   std::string str_secnd;
   std::string str_third;

   bool correct_input = false;

   while (!correct_input)
   {
       std::cout << "Enter the first line\n=>";
       std::getline(std::cin, str_first);

       std::cout << "Enter the second line\n=>";
       std::getline(std::cin, str_secnd);

       std::cout << "Enter the third line\n=>";
       std::getline(std::cin, str_third);

       correct_input = (check_correct_symbol (str_first) &&
                        check_correct_symbol (str_secnd) &&
                        check_correct_symbol (str_third));

       if (!correct_input)
           std::cout << "Incorrect input, try again!\n";
   }





   char winner = get_win (str_first, str_secnd, str_third);

    std::cout << "winner is " << winner << std::endl;

   //запустить в цикле get_elmnt чтобы вывести на экран
  std::cout << "-------------\n";

  //int count0 = get_count ('O', str_first, str_secnd, str_third);
  //int countX = get_count ('X', str_first, str_secnd, str_third);
  //std::cout << "count0  " << count0 << std::endl;
  //std::cout << "countX  " << countX << std::endl;







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