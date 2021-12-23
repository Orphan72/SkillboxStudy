#include <iostream>
#include <fstream>
#include <vector>

int const NUM = 13;
int const SIZE = 20;

enum qustAnsw
{
    QUES,
    ANSW
};


void rotation (int &sec)
{
    int offset = 0;

    std::cout << "Please, spint the dream" << std::endl;
    std::cout << "Enter offset\n=>";
    std::cin >> offset;
    sec += offset;
    while (sec > NUM) sec -= NUM;

    std::cout << "Sector is  " << sec << std::endl;
}

void show (std::string pth, char* buffer, qustAnsw qa)
{
    std::fstream text;
    text.open(pth);

    if (!text.is_open())
    {
        std::cout << "The file was not opened!!!\n";
    }
    else
    {
        if (qa == QUES)
        {
            std::cout << "Attention! The question:\n";
        }
        else
        {
            std::cout << "The correct answer is - ";
        }
        std::cout << "===================\n";

        while (!text.eof())
        {
            text.read(buffer, SIZE - 1);

            if (text.gcount() < SIZE)
            {
                int count = text.gcount();
                buffer[count] = 0;
            }
            std::cout << buffer;
        }
    }
    std::cout << "\n===================\n";
}


int main()
{
    std::string pathQuesBegin = "..//data//questions//Q";
    std::string pathAnswBegin = "..//data//answers//A";
    std::string pathEnd = ".txt";
    std::string pathQues = " ";
    std::string pathAnsw = " ";
    int sector = 0;
    std::vector <std::string> sectChar = {"01","02","03","04","05","06","07","08","09","10","11","12","13"};



    std::string answer = " ";
    char question [SIZE];
    char correctAnswer [SIZE];


    rotation(sector);
    std::cout << "Sector is  " << sector << std::endl;
    //sectChar = (char) (sector + ASCIIOFFSET);
    //std::cout << "sect  " << sectChar << std::endl;

    pathQues = pathQuesBegin + sectChar [sector -1] + pathEnd;



    std::cout << "Path is  " << pathQues << std::endl;



        show (pathQues, question, QUES);
        /*

        while (!text.eof()) {
            text.read(question, sizeof(question) -1);

            if (text.gcount() < SIZE - 1)
            {
                int count = text.gcount();
                question [count] = 0;
            }
            std::cout << question << std::endl;
        }

*/




        std::cout << "Enter your answer:\n";

        std::cin >> answer;

        std::cout << "Answer " << answer << std::endl;

    //}







    return 0;
}

/*
Как происходит игра
        В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет.
        Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение)
        относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор,
        который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий неигравший за ним.
        В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла
данного сектора. Вопрос показывается на экране.

После того как вопрос показан, от игрока ожидается ответ на него.
Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом,
который хранится во втором файле, ассоциированном с активным сектором.
Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.

Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов.
После этого называется победитель и программа заканчивает работу.

 */
