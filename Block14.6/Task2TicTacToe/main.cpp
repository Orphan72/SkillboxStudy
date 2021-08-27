#include <iostream>
const int SIZE = 3;

void displayField (char vec [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << vec [i][j] << " | ";
        }
        std::cout << " \n-----------\n";
    }
}

char checkWin (char vec [SIZE][SIZE])
{
    char winner = 'N';
    for (int i = 0; i < SIZE; i++)
    {
        int k = 0;
        int n = 0;
        if (vec[i][k] == vec[i][++k] && vec[i][k] == vec[i][++k] && vec[i][k] != ' ')
        {
            winner = vec[i][k];
            return winner;
        }

        else if  (vec [n][i] == vec [++n][i] && vec [n][i] == vec [++n][i] && vec [n][i] != ' ')
        {
            winner = vec [n][i];
            return winner;
        }
    }
    return winner;
}

int main()
{
   char field [SIZE][SIZE];
   int row = 0;
   int col = 0;
   int turnCounter = 0;
   char win = 'N';

   for (int i = 0; i < SIZE; i++)
   {
       for (int j = 0; j < SIZE; j++)
       {
            field [i][j] = ' ';
       }
   }
   displayField (field);

   while (true)
   {
       bool correct = false;
       while (!correct)
       {
           std::cout << "Player X, your turn. Input row\n=>";
           std::cin >> row;
           std::cout << "Input column\n=>";
           std::cin >> col;
           correct = (row > 0 && row <= SIZE) && (col > 0 && col <= SIZE);
           if (!correct)
           {
               std::cout << "incorrect input. Please, try again\n";
           }
           else if (field[row - 1][col - 1] != ' ')
           {
               std::cout << "This cell is busy. Please, try again\n";
               correct = false;
           }
       }

       field[row - 1][col - 1] = 'X';
       displayField (field);
       win = checkWin(field);
       turnCounter++;
       if (win == 'X' || turnCounter == SIZE*SIZE) break;
       else {
           correct = false;
           while (!correct) {
               std::cout << "Player O, your turn. Input row\n=>";
               std::cin >> row;
               std::cout << "Input column\n=>";
               std::cin >> col;
               correct = (row > 0 && row <= SIZE) && (col > 0 && col <= SIZE);
               if (!correct) {
                   std::cout << "incorrect input. Please, try again\n";
               } else if (field[row - 1][col - 1] != ' ') {
                   std::cout << "This cell is busy. Please, try again\n";
                   correct = false;
               }
           }
           field[row - 1][col - 1] = 'O';
           displayField(field);
           win = checkWin(field);
           turnCounter++;
           if (win == 'O')
               break;
       }
   }

   if (win == 'N')
       std::cout << "Nobody won\n ";
   else
       std::cout << "Player " << win << " won!\n";
   return 0;
}

/*
Задача 2. Крестики-нолики
Старинная-добрая игра на страницах всех школьных тетрадей. Поле размером 3х3 представлено в виде двумерного массива с типом элементов char.
Помните тот символьный тип из предыдущего модуля? Теперь он нам и пригодится.
Участвуют два игрока, которые ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ - ‘X’ или ‘O’ (буквы латинского алфавита).
Как только у одного из игроков будет установлено подряд три крестика или три нолика - он побеждает. Если свободных клеток не осталось,
а трёх совпадающих элементов не найдено - объявляется ничья. Для простоты, мы не будем рассматривать диагональные совпадения, а только строго вертикальные
либо строго горизонтальные.
Изначально всё поле инициализируется символом пробела - ‘ ‘. Это можно сделать сразу при объявлении, либо с помощью вложенного цикла.
На каждом ходе, при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение и игрок должен указать координаты клетки повторно.
После каждого хода надо выводить в консоль текущее состояние всего игрового поля, для наглядности.

Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с помощью вложенного цикла,
сразу проверяя и вертикаль и горизонталь а как именно - попробуйте догадаться сами.
 */