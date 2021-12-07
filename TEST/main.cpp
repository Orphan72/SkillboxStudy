#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main()
{

  std::vector<double> purse;
  std::ifstream bank;
  bank.open ("E:\\My documents\\SkillBox\\bank.txt");

  double sum = 0;
  while (!bank.eof())
  {
      double money;
      bank >> money;
      purse.push_back(money);
  }



  for (int i = 0; i < purse.size(); ++i)
  {
      sum += purse [i];
  }

  std::cout << sum << std::endl;

    bank.close();



}




/*

evendigits(9 223 372 036 854 775 806, ans);

//ans == 10

Пояснение: 9 223 372 036 854 775 806
*/