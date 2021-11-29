#include <iostream>

int count = 0;

int foo (int num)
{
    //int count = 0;

    if (num == 0)
        return count;

    if (num%2 == 0)
        count++;

    return foo (num/10);


}


int main()
{

    long num = 45602;
    int a = 0;

    a = foo (45632);

    std::cout << a << std::endl;

    return 0;
}




/*
int main()
{

    long num = 45602;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {

        if (num % 2 == 0)
        {
            count++;

        }
        num = num / 10;
        std::cout << count << std::endl;
        std::cout << num << std::endl;
    }
    std::cout << count << std::endl;
    return 0;
}
*/



/*
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, а возвращает void.
После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n.

Пример:

int ans;

evendigits(9 223 372 036 854 775 806, ans);

//ans == 10

Пояснение: 9 223 372 036 854 775 806
*/