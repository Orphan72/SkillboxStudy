#include <iostream>

char getElmnt (int x, int y, std::string str1, std::string str2, std::string str3) {
    std::string line = "";
    if (y == 1)
        line = str1;
    else if (y == 2)
        line = str2;
    else
        line = str3;
    return line [x-1];
}

void drawField (std::string str1, std::string str2, std::string str3){
    for (int y = 1; y < 4; y++) {
        for (int x = 1; x < 4; x++) {
            std::cout << "| " << getElmnt (x, y, str1, str2, str3) << " ";
        }
        std::cout << "|\n";
        std::cout << "-------------\n";
    }
}

int getCount (char ch, std::string str1, std::string str2, std::string str3) {
    int count = 0;
    for (int y = 1; y < 4; y++) {
        for (int x = 1; x < 4; x++) {
            if (getElmnt (x, y, str1, str2, str3) == ch) count++;
        }
    }
    return count;
}

bool checkCorrectSymbol (std::string str) {
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

char getWin (std::string str1, std::string str2, std::string str3) {
    char element = '-';
    int countWin = 0;
    for (int i = 1; i < 4; i++) {
        if ((getElmnt(1, i, str1, str2, str3) ==
             getElmnt(2, i, str1, str2, str3)) &&
            (getElmnt(2, i, str1, str2, str3) ==
             getElmnt(3, i, str1, str2, str3))) {
             element = getElmnt(1, i, str1, str2, str3);
            if (element != '.') countWin++;
        }
        else if ((getElmnt(i, 1, str1, str2, str3) ==
                  getElmnt(i, 2, str1, str2, str3)) &&
                 (getElmnt(i, 2, str1, str2, str3) ==
                  getElmnt(i, 3, str1, str2, str3))) {
            element = getElmnt(i, 1, str1, str2, str3);
            if (element != '.') countWin++;
        }
    }
    if ((getElmnt(1, 1, str1, str2, str3) ==
         getElmnt(2, 2, str1, str2, str3)) &&
        (getElmnt(2, 2, str1, str2, str3) ==
         getElmnt(3, 3, str1, str2, str3))) {
        element = getElmnt(1, 1, str1, str2, str3);
        if (element != '.') countWin++;
    }
    else if ((getElmnt(3, 1, str1, str2, str3) ==
              getElmnt(2, 2, str1, str2, str3)) &&
             (getElmnt(2, 2, str1, str2, str3) ==
              getElmnt(1, 3, str1, str2, str3))) {
        element = getElmnt(3, 1, str1, str2, str3);
        if (element != '.') countWin++;
    }
    if (countWin > 1) return 'N';
    return element;
}

bool checkCorrectGame (std::string str1, std::string str2, std::string str3) {
        if (getWin (str1, str2, str3) == 'N')
            return false;
        else if (getCount ('O', str1, str2, str3) >
             getCount ('X', str1, str2, str3))
            return false;
        else if (getCount ('X', str1, str2, str3) >
                 getCount ('O', str1, str2, str3) + 1)
            return false;
         else if (getWin (str1, str2, str3) == 'X' &&
                 (getCount ('X', str1, str2, str3) ==
                  getCount ('O', str1, str2, str3)))
             return false;
         else if (getWin (str1, str2, str3) == 'O' &&
                 (getCount ('X', str1, str2, str3) >
                  getCount ('O', str1, str2, str3)))
             return false;
         else return true;
}

int main() {
   std::string strFirst;
   std::string strSecnd;
   std::string strThird;
   bool correctInput = false;
   while (!correctInput) {
       std::cout << "Enter the first line\n=>";
       std::getline(std::cin, strFirst);

       std::cout << "Enter the second line\n=>";
       std::getline(std::cin, strSecnd);

       std::cout << "Enter the third line\n=>";
       std::getline(std::cin, strThird);

       correctInput = (checkCorrectSymbol (strFirst) &&
                        checkCorrectSymbol (strSecnd) &&
                        checkCorrectSymbol (strThird));
       if (!correctInput)
           std::cout << "Incorrect input, try again!\n";
   }

   drawField (strFirst, strSecnd, strThird);

   bool correctGame = checkCorrectGame (strFirst, strSecnd, strThird);
   if (!correctGame)
        std::cout << "Incorrect\n";
    else {
        char winner = getWin (strFirst, strSecnd, strThird);

        if (winner == 'O')  std::cout << "Vanya won\n";
        else if (winner == 'X')  std::cout << "Petya won\n";
        else {
            std::cout << "Nobody\n";
        }
    }

    return 0;
}
