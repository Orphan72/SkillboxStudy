#include <iostream>
#include <vector>

//TODO
// оформить рандомное заполнение в отдельную функцию
// написать функцию для показа домов

const int MINCOUNTROOM = 2;
const int MAXNCOUNTROOM = 4;
const int MAXNCOUTFLOR = 3;
const float MINAREASECTION = 50.0;
const float MAXAREASECTION = 1000.0;
const float MINAREABUILDING = 20.0;
const float MINAREAROOM = 10.0;



enum streetNames
{
    UNKNOWNSTREET,
    LESNAYA,
    OZERNAYA,
    RECNAYA,
    PYLNAYA,
    maxCountStreet
};

enum buildNames
{
    UNKNOWNBUILD,
    GARAGE,
    BATHHOUSE,
    BARN,
    maxEnumBuild
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
    float hight = 0.0;
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

    int streetCont = 0;
    std::cout << "Enter count of street\n=>";
    streetCont = 1;

    std::vector<street> strts (streetCont);

    for (int i = 0; i < streetCont; i++)
    {
        strts[i].name = (streetNames)(i + 1);
        strts[i].sectionCount = 2;   // need enter
        for (int j = 0; j < strts[i].sectionCount; i++)
        {
            strts[i].sect[j].number = i * strts[i].sectionCount + j + 1;
            strts[i].sect[j].area = 500.0; // введите площадь участка (от 100 до 1000)
            float areaSect = strts[i].sect[j].area;
            strts[i].sect[j].hs.area = 50.0; // введите площадь дома (между 50 и площадью участка)
            float areaHouse = strts[i].sect[j].hs.area;
            float areaRestSect = areaSect - areaHouse;
            int maxCountBuild = (areaRestSect)/MINAREABUILDING;




            strts[i].sect[j].buildlCount = 1; // введите количество строений (от 0 до maxCoutnBuild)

            // остаток площади все таки считать
            while (areaRestSect >= 20.0)
            {
                for (int k = 0; k < strts[i].sect[j].buildlCount; k++)
                {
                    strts[i].sect[j].build[k].area = 20.0; // введите площадь строения (меньше, чем остсток площади, но больше чем 20)
                    strts[i].sect[j].build[k].name = GARAGE; // от 0 до количества в enum
                    if (strts[i].sect[j].build[k].name != BATHHOUSE)
                    {
                        strts[i].sect[j].build[k].stove = false;
                    }
                    else
                        strts[i].sect[j].build[k].stove = false; // введите наличие трубы в строени

                    areaRestSect -= strts[i].sect[j].build[k].area;
                    if (areaRestSect < 20.0)
                        break;
                }
                if (areaRestSect < 20.0)
                    std::cout << "TestStopLoopWhile\n";
            }



            strts[i].sect[j].hs.florCount = 2; // введите количество этажей (от 1 до 3)
            int countFlor = strts[i].sect[j].hs.florCount;
            strts[i].sect[j].hs.stove = false;// введите наличие трубы в доме


            int maxCountRoomFlor = areaHouse/MINAREAROOM;

            if (maxCountRoomFlor > 4)
                maxCountRoomFlor = 4;

            for (int l = 0; l < strts[i].sect[j].hs.florCount; l++)
            {
                strts[i].sect[j].hs.flr[l].num = l + 1;
                strts[i].sect[j].hs.flr[l].hight = 2.0; //введите высоту потолков (от 2,5 до 4)
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

                while (areaRestFlor > 10.0)
                {
                    for (int m = 0; m < strts[i].sect[j].hs.flr[l].roomCount; m++)
                    {
                        strts[i].sect[j].hs.flr[l].rm[m].area = 20.0; // площадь не больше остатка площади этажа
                        areaRestFlor -= strts[i].sect[j].hs.flr[l].rm[m].area;
                    }
                }



            }




        }

    }












    return 0;
}
