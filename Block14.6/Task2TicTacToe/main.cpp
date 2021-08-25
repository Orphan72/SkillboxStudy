#include <iostream>
const int SIZE = 3;

void displayField (char vec [SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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
        if (vec [i][0] == vec [i][1] && vec [i][1] == vec [i][2] && vec [i][0] != '5')
        {
            winner = vec [i][0];
            return winner;
        }
        else if  (vec [0][i] == vec [1][i] && vec [1][i] == vec [2][i] && vec [0][i] != '5')
        {
            winner = vec [i][0];
            return winner;
        }
    }
    return winner;
}


bool searchGap (char vec [SIZE][SIZE])
{
    int countGap = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; i++)
        {
            if (vec [i][j] == ' ')
                countGap++;
        }
    }

    if (countGap == 0)
        return false;
}

int main() {

   char field [SIZE][SIZE];
   int x = 0;
   int y = 0;


   for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j < SIZE; j++) {
            field [i][j] = '5';
       }
   }
   displayField (field);
   char win = ' ';

   //todo
   bool gap = true;


   //todo - while, use search gap
   for (int i = 0; i < 4; i++) {

       gap = searchGap (field);
       std::cout << "Player X, your turn. Input coordinates\n=>";
       std::cin >> x;
       std::cout << "=>";
       std::cin >> y;

       field[y - 1][x - 1] = 'X';

       displayField (field);

       win = checkWin(field);
       if (win) {
           std::cout << "Stop!\n";
           break;
       }


       std::cout << "Player O, your turn. Input coordinates\n=>";
       std::cin >> x;
       std::cout << "=>";
       std::cin >> y;

       field[y - 1][x - 1] = 'O';
       displayField (field);

       win = checkWin(field);
       if (win) {
           std::cout << "Stop!\n";
           break;
       }
   }

   std::cout << "Winner is " << win << std::endl;





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