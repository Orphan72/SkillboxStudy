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
        if (vec[i][k] == vec[i][k + 1] && vec[i][k + 1] == vec[i][k + 2] && vec[i][k] != ' ')
        {
            winner = vec[i][k];
            return winner;
        }

        else if  (vec [n][i] == vec [n + 1][i] && vec [n][i] == vec [n + 2][i] && vec [n][i] != ' ')
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

