#include <iostream>
#include <fstream>
#include <vector>

const int NUMSECT = 13;
const int BUFSIZE = 20;
const int MAXPOINT = 6;

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
    while (sec > NUMSECT) sec -= NUMSECT;
}

void show (std::string pth, char* buffer, qustAnsw qa, bool &isOpn)
{
    std::fstream text;
    text.open(pth);

    if (!text.is_open())
    {
        isOpn = false;
    }
    else
    {
        if (qa == QUES)
        {
            std::cout << "Attention! The question is:";
        }
        else
        {
            std::cout << "The correct answer is:";
        }
        std::cout << "\n===================\n";

        while (!text.eof())
        {
            text.read(buffer, BUFSIZE - 1);

            if (text.gcount() < BUFSIZE)
            {
                int count = text.gcount();
                buffer[count] = 0;
            }
            std::cout << buffer;
        }
    }
    std::cout << "\n===================\n";
    text.close();
}

void showConclusion (const char* corAnsw, std::string answ, int& cExp, int& cView )
{
        if (corAnsw == answ)
        {
            std::cout << "Correct\n";
            std::cout << "The point is awarded to experts\n";
            cExp++;

        }
        else
        {
            std::cout << "Nooo\n";
            std::cout << "The point is awarded to viewers\n";
            cView++;
        }

        std::cout << "The Score is";
        std::cout << "\n====================\n";
        std::cout << cView << " : " <<  cExp;
        std::cout << " in favor of ";
        std::cout << ( cView > cExp ? "Viewers" : "Experts");
        std::cout << "\n====================\n";
};

void checksector (std::vector<int> scts, int& sec)
{
    for (int i = 0; i < scts.size(); i++)
    {
        if (sec == scts [i])
        {
            std::cout << "Sector " << sec << " already used\n";
            std::cout << "Will be choosed next one\n";
            sec++;
            while (sec > NUMSECT) sec -= NUMSECT;
            checksector (scts, sec);
         }
    }
}

int main()
{
    std::vector <std::string> sectors = {"01","02","03","04","05","06","07","08","09","10","11","12","13"};
    int sector = 0;
    std::vector <int> usedSectors;

    std::string pathQuesBegin = "..//data//questions//Q";
    std::string pathAnswBegin = "..//data//answers//A";
    std::string pathEnd = ".txt";
    std::string pathQues = " ";
    std::string pathAnsw = " ";

    std::string answer = " ";
    char question [BUFSIZE];
    char correctAnswer [BUFSIZE];

    bool isFileOpened = true;

    int countViewers = 0;
    int countExperts = 0;

    while (countViewers < MAXPOINT && countExperts < MAXPOINT)
    {
        rotation(sector);

        checksector (usedSectors, sector);
        std::cout << "Sector " << sector << std::endl;
        usedSectors.push_back(sector);

        pathQues = pathQuesBegin + sectors [sector - 1] + pathEnd;
        pathAnsw = pathAnswBegin + sectors [sector - 1] + pathEnd;

        show(pathQues, question, QUES, isFileOpened);

        if (!isFileOpened)
        {
            std::cout << "The file was not opened!!!\n";
        }
        else
        {
            std::cout << "Enter your answer:\n";
            std::cin >> answer;
            std::cout << "Answer " << answer << std::endl;
            show(pathAnsw, correctAnswer, ANSW, isFileOpened);

            if (!isFileOpened)
            {
                std::cout << "The file was not opened!!!\n";
            }
            else
            {
                showConclusion(correctAnswer, answer, countExperts, countViewers);
            }
        }
    }

    std::cout << ( countViewers > countExperts ? "Viewers " : "Experts ");
    std::cout << " WON!!\n";

    return 0;
}

