#include <iostream>
#include <vector>

//TODO
//оформить заполнение в отдельную функцию
// написать функцию для показа домов

// создать функцию для рандомного заполнения

const int MINCOUTSTREET = 4;
const int MAXCOUTSTREET = 4;

const int MINCOUTSECTION = 1;
const int MAXCOUTSECTION = 10;

const int MINCOUTFLOR = 3;
const int MAXCOUTFLOR = 3;

const int MINCOUNTROOM = 2;
const int MAXCOUNTROOM = 4;

const float MINAREASECTION = 100.0;
const float MAXAREASECTION = 1000.0;

const float MINAREAHOUSE = 50.0;
const float MINAREABUILDING = 20.0;

const float MINAREAROOM = 10.0;

const float MINHEIGHTFLOOR = 2.5;
const float MAXHEIGHTFLOOR = 4.5;

const float MAXSHARE = 0.9;



enum streetNames
{
    UNKNOWNSTREET,
    LESNAYA,
    OZERNAYA,
    RECNAYA,
    PYLNAYA
};

enum buildNames
{
    UNKNOWNBUILD,
    GARAGE,
    BATHHOUSE,
    BARN
};

enum roomNames
{
    UNKNOWROOM,
    LIVINGROOM,
    BATHROOM,
    KITCHEN,
    BEDROOM,
    NURSERY
};

struct room
{
    roomNames name = UNKNOWROOM;
    float area = 0.0;
};

struct flor
{
    int num = 0;
    float height = 0.0;
    int roomCount = 1;
    std::vector <room> rm;

};

struct house
{
    int florCount = 1;
    float area = 0.0;
    std::vector<flor> flr;
    bool stove = false;
};


struct building
{
    buildNames name = UNKNOWNBUILD;
    float area = 0.0;
    bool stove = false;
};

struct section
{
    int number = 0;
    float area = 0.0;
    int buildlCount = 1;
    house hs;
    std::vector<building> build;
};

struct street
{
    streetNames name = UNKNOWNSTREET;
    int sectionCount = 1;
    std::vector <section> sect;
};


int main()
{

    int streetCount = 0;

    std::cout << "Enter count of street from " << MINCOUTSTREET << " to " << MAXCOUTSTREET << "\n=>";

    //>>>>>>>>>>>>>>>>>>>>>>
    streetCount = 1;

    std::vector<street> strts (streetCount);

    for (int i = 0; i < streetCount; i++)
    {
        strts[i].name = (streetNames)(i + 1);

        std::cout << "Enter count of section from " << MINCOUTSECTION << " to " << MAXCOUTSECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>
        strts[i].sectionCount = 2;   // need enter


        for (int j = 0; j < strts[i].sectionCount; i++)
        {
            strts[i].sect[j].number = i * strts[i].sectionCount + j + 1;

            std::cout << "Enter section's area from " << MINAREASECTION << " to " << MAXAREASECTION << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            strts[i].sect[j].area = 100.0; // введите площадь участка (от 100 до 1000)

            float areaSect = strts[i].sect[j].area;

            std::cout << "Enter hous' area from " << MINAREAHOUSE << " to " << areaSect * MAXSHARE << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            strts[i].sect[j].hs.area = 50.0; // введите площадь дома (между 50 и площадью участка)

            float areaHouse = strts[i].sect[j].hs.area;
            float areaRestSect = areaSect - areaHouse;
            int maxCountBuild = (areaRestSect)/MINAREABUILDING;

            std::cout << "Enter count of buildings from 0 to " << maxCountBuild << "\n=>";

           //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            strts[i].sect[j].buildlCount = 1;

            // остаток площади
            while (areaRestSect >= MINAREABUILDING)
            {
                for (int k = strts[i].sect[j].buildlCount; k > 0; k--)
                {

                    std::cout << "Enter count of buildings from 0 to " << MINAREABUILDING;
                    std::cout << " to " << areaRestSect - MINAREABUILDING * (float)(k - 1) << "\n=>";

                    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                    strts[i].sect[j].build[k].area = 20.0; // введите площадь строения (меньше, чем остсток площади, но больше чем 20)


                    std::cout << "Enter name of buildings: " << GARAGE << " or " << BATHHOUSE << " or " << BARN << "\n=>";

                    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                    strts[i].sect[j].build[k].name = GARAGE; // от 0 до количества в enum

                    if (strts[i].sect[j].build[k].name != BATHHOUSE)
                    {
                        strts[i].sect[j].build[k].stove = false;
                    }
                    else

                        std::cout << "Is there tube on the roof?\n=>";
                        strts[i].sect[j].build[k].stove = false; // введите наличие трубы в строени

                    areaRestSect -= strts[i].sect[j].build[k].area;

                    std::cout << "areaRestSect is " << areaRestSect;

                    if (areaRestSect < MINAREABUILDING)
                        break;
                }
            }


            std::cout << "Enter count of floors from " << MINCOUTFLOR << " to " << MAXCOUTFLOR << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            strts[i].sect[j].hs.florCount = 2; // введите количество этажей (от 1 до 3)

            int countFlor = strts[i].sect[j].hs.florCount;

            std::cout << "Is there tube on the roof?\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            strts[i].sect[j].hs.stove = false;// введите наличие трубы в доме

            int maxCountRoomFlor = areaHouse/MINAREAROOM;

            if (maxCountRoomFlor > MAXCOUNTROOM)
                maxCountRoomFlor = MAXCOUNTROOM;

            for (int l = 0; l < countFlor; l++)
            {
                strts[i].sect[j].hs.flr[l].num = l + 1;

                std::cout << "Enter a height of floor from " << MINHEIGHTFLOOR << " to " << MAXHEIGHTFLOOR << "\n=>";
                strts[i].sect[j].hs.flr[l].height = 2.0; //введите высоту потолков (от 2,5 до 4)

                std::cout << "Enter a count of room from " << MINCOUNTROOM << " to " << maxCountRoomFlor << "\n=>";
                strts[i].sect[j].hs.flr[l].roomCount = 2; //введите количество комнта (минимум 2, максимум 4)

                float areaRestFlor = strts[i].sect[j].hs.area;


                for (int m = 0; m < MINCOUNTROOM; m++)
                {
                    strts[i].sect[j].hs.flr[l].rm[m].name = (roomNames)(m + 1);
                }

                for (int m = MINCOUNTROOM; m < strts[i].sect[j].hs.flr[l].roomCount; m++)
                {
                    strts[i].sect[j].hs.flr[l].rm[m].name = (roomNames)(m + 1);
                }

                while (areaRestFlor > MINAREAROOM)
                {
                    for (int m = strts[i].sect[j].hs.flr[l].roomCount; m > 0; m--)
                    {

                        std::cout << "Enter room's area from  " << MINAREAROOM;
                        std::cout << "to " << areaRestFlor - MINAREAROOM * (float)(m - 1) << "\n=>";

                        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                        strts[i].sect[j].hs.flr[l].rm[m].area = 20.0; // площадь не больше остатка площади этажа
                        areaRestFlor -= strts[i].sect[j].hs.flr[l].rm[m].area;

                        std::cout << "Rest area flor is " << areaRestFlor << "\n=>";

                        if (areaRestFlor < MINAREAROOM)
                        {
                            strts[i].sect[j].hs.flr[l].rm[m].area += areaRestFlor;
                            break;
                        }


                    }
                }
            }




        }

    }












    return 0;
}
