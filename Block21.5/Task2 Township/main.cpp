#include <iostream>
#include <vector>
#include <ctime>

//TODO

// запись в файл?
// чтение из файла?

// создать функцию для рандомного заполнения

const int MINCOUTSTREET = 1;
const int MAXCOUTSTREET = 4;

const int MINCOUTSECTION = 1;
const int MAXCOUTSECTION = 10;

const int MINCOUTFLOR = 1;
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

struct storey
{
    int num = 0;
    float height = 0.0;
    int roomCount = 1;
    room rm;
    std::vector <room> rooms;
};

struct house
{
    int florCount = 1;
    float area = 0.0;
    storey floor;
    std::vector<storey> flrs;
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
    int buildlCount = 0;
    house hs;
    building build;
    std::vector<building> blds;
};

struct street
{
    streetNames name = UNKNOWNSTREET;
    int sectionCount = 1;
    section sctn;
    std::vector <section> sects;
};

void fullRoom (storey &flr, float area)
{
    int nm = 0;
    //while (area > MINAREAROOM)
    //{
        for (int m = flr.roomCount; m > 0; m--)
        {

            std::cout << "Enter name of room from " << LIVINGROOM << " to " << NURSERY << "\n";
            std::cout << LIVINGROOM << " - Livingroom\n" << BATHROOM << " - Bathhouse\n";
            std::cout << KITCHEN << " - Kitchen\n" << BEDROOM << " - Bedroom\n" << NURSERY << " - Nursery\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            std::cin >> nm;
            flr.rm.name = (roomNames)nm;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            //str.sctn.hs.floor.rm.name = (roomNames)(4 - m + 1) ; // если по порядку

            std::cout << "Enter room's area from  " << MINAREAROOM;
            std::cout << " to " << area - MINAREAROOM * (float)(m - 1) << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            std::cin >> flr.rm.area;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            //flr.rm.area = 12.0; // площадь не больше остатка площади этажа

            area -= flr.rm.area;

            std::cout << "Rest area flor is " << area << "\n";

            flr.rooms.push_back(flr.rm);
            //if (area < MINAREAROOM) break;
        }
    //}
}

void fullStorey (house &hs)
{
    int maxCountRoomFlor = hs.area/MINAREAROOM;

    if (maxCountRoomFlor > MAXCOUNTROOM)
        maxCountRoomFlor = MAXCOUNTROOM;

    for (int l = 0; l < hs.florCount; l++)
    {
        hs.floor.num = l + 1;

        std::cout << "Enter a height of floor from " << MINHEIGHTFLOOR << " to " << MAXHEIGHTFLOOR << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> hs.floor.height;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //hs.floor.height = 2.0; //введите высоту потолков (от 2,5 до 4)

        std::cout << "Enter a count of room from " << MINCOUNTROOM << " to " << maxCountRoomFlor << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> hs.floor.roomCount;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //hs.floor.roomCount = 4; //введите количество комнта (минимум 2, максимум 4)

        float areaRestFlor = hs.area;

        fullRoom(hs.floor, areaRestFlor);

        hs.flrs.push_back(hs.floor);
        hs.floor.rooms.clear();
    }
}

void fullYard (section &sct, float area)
{
    int nm = 0;
    // остаток площади
    //while (area > MINAREABUILDING)
    //{
        for (int k = sct.buildlCount; k > 0; k--)
        {
            std::cout << "Enter buildings area from " << MINAREABUILDING;
            std::cout << " to " << area - MINAREABUILDING * (float) (k - 1) << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            std::cin >> sct.build.area;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            //sct.build.area = 20.0; // введите площадь строения (меньше, чем остсток площади, но больше чем 20)

            std::cout << "Enter name of building from " << GARAGE << " to " << BARN << "\n";
            std::cout << GARAGE << " - Garage " << BATHHOUSE << " - Bathhouse " << BARN << "- Barn\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            std::cin >> nm;
            sct.build.name = (buildNames)nm;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            //sct.build.name = BATHHOUSE; // от 0 до количества в enum

            sct.build.stove = (sct.build.name == BATHHOUSE);

            area -= sct.build.area;

            std::cout << "areaRestSect is " << area << std::endl;

            sct.blds.push_back(sct.build);


            //if (area < MINAREABUILDING)
              //  break;
        }
    //}
}

void fullStreet (street &str, int n)
{

    for (int j = 0; j < str.sectionCount; j++) {
        str.sctn.number = n*MAXCOUTSTREET + j + 1;

        std::cout << "Enter section's area from " << MINAREASECTION << " to " << MAXAREASECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sctn.area;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //str.sctn.area = 100.0; // введите площадь участка (от 100 до 1000)

        float areaSect = str.sctn.area;

        std::cout << "Enter hous' area from " << MINAREAHOUSE << " to " << areaSect * MAXSHARE << "\n=>";

       //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sctn.hs.area;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       //str.sctn.hs.area = 50.0; // введите площадь дома (между 50 и площадью участка)

        float areaRestSect = areaSect - str.sctn.hs.area;
        int maxCountBuild = (areaRestSect) / MINAREABUILDING;

        std::cout << "Enter count of buildings from 0 to " << maxCountBuild << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sctn.buildlCount;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //str.sctn.buildlCount = 2;

        if (str.sctn.buildlCount)
        {
            fullYard(str.sctn, areaRestSect);
        }



        std::cout << "Enter count of floors from " << MINCOUTFLOR << " to " << MAXCOUTFLOR << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sctn.hs.florCount;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //str.sctn.hs.florCount = 2; // введите количество этажей (от 1 до 3)

        std::cout << "Is there tube on the roof?\n";
        std::cout << "1 - tube is\n0 - tube is not\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sctn.hs.stove;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //str.sctn.hs.stove = true;// введите наличие трубы в доме

        fullStorey(str.sctn.hs);

        str.sects.push_back(str.sctn);
        str.sctn.hs.flrs.clear ();
    }
}

void showStreetName (streetNames strNm)
{
    if (strNm == UNKNOWNSTREET)
        std::cout << "Unknown\n";
    else if (strNm == LESNAYA)
        std::cout << "Lesnaya str.\n";
    else if (strNm == OZERNAYA)
        std::cout << "Ozernaya str.\n";
    else if (strNm == RECNAYA)
        std::cout << "Rechnaya str.\n";
    else
        std::cout << "Pylnaya str.\n";
}


void showBuildingName (buildNames bldNm)
{
    if (bldNm == UNKNOWNBUILD)
        std::cout << "Unknown\n";
    else if (bldNm == GARAGE)
        std::cout << "\t\tGarage, ";
    else if (bldNm == BATHHOUSE)
        std::cout << "\t\tBathhouse, ";
    else
        std::cout << "\t\tBarn, ";
}

void showRoomName (roomNames roomNm)
{
    if (roomNm == UNKNOWROOM)
        std::cout << "Unknown\n";
    else if (roomNm == LIVINGROOM)
        std::cout << "\t\t\tLivingroom, ";
    else if (roomNm == BATHROOM)
        std::cout << "\t\t\tBathroom, ";
    else if (roomNm == KITCHEN)
        std::cout << "\t\t\tKitchen, ";
    else if (roomNm == BEDROOM)
        std::cout << "\t\t\tBedroom, ";
    else
        std::cout << "\t\t\tNursery, ";
}

void showRoom (std::vector <room> rms, int n)
{
    for (int i = 0; i < n; i++)
    {
        showRoomName (rms [i].name);
        std::cout << rms[i].area << " sq. m\n";
    }
}

void showFloor (std::vector <storey> flrs, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n\t\tFloor # " << flrs[i].num << " contains ";
        std::cout << flrs [i].roomCount << " rooms:\n";

        showRoom(flrs[i].rooms, flrs[i].roomCount);
        std::cout << "\t\t\tHeight or " << flrs[i].num << " fl. is " << flrs[i].height << " m\n";

    }
}

void showBuilding (std::vector <building> bls, int n)
{
    for (int i = 0; i < n; i++)
    {
        showBuildingName(bls [i].name);
        std::cout << bls [i].area << " sq.m\n";
        if (bls[i].stove == true)
        {
            std::cout << "\t\t\tchimney on the roof\n";
        }
    }
}

void showHouse (house hs)
{

    if (hs.stove == true)
    {
        std::cout << ", chimney on the roof\n";
    }

    showFloor (hs.flrs, hs.florCount);
}

void showSection (std::vector<section> scts, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\tSection # " << scts [i].number << "\n";
        std::cout << "\t\tArea: " << scts [i].area << "\n";
        std::cout << "\t\tHOUSE:\n";
        std::cout << "\t\t\tArea: " << scts[i].hs.area << "\n";
        std::cout << "\t\t\tNumber of floors: " << scts[i].hs.florCount << "\n";




        showHouse (scts[i].hs);
        if (!scts[i].buildlCount)
        {
            std::cout << "\tThere is no any add buildings in the yard\n";
        }
        else
        {
            std::cout << "\tBuildings:\n";
            showBuilding(scts[i].blds, scts[i].buildlCount);
        }

    }
}

void showStreet (std::vector<street> strs, int n)
{
    for (int i = 0; i < n; i++)
    {
        showStreetName(strs[i].name);
        std::cout << "\tCount of sections is " << strs[i].sectionCount << std::endl;

        showSection(strs[i].sects, strs[i].sectionCount);
    }
}


int main()
{
    int streetCount = 0;

    std::cout << "Enter count of street from " << MINCOUTSTREET << " to " << MAXCOUTSTREET << "\n=>";

    //>>>>>>>>>>>>>>>>>>>>>>
    std::cin >> streetCount;
    //>>>>>>>>>>>>>>>>>>>>>>
    //streetCount = 1;

    std::vector<street> strts;



    for (int i = 0; i < streetCount; i++)
    {
        street str;
        str.name = (streetNames)(i + 1);

        std::cout << "Enter count of section from " << MINCOUTSECTION << " to " << MAXCOUTSECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sectionCount;
        //>>>>>>>>>>>>>>>>>>>>>>
        //str.sectionCount = 2;   // need enter

        fullStreet (str, i);

        strts.push_back(str);
    }

std::cout << "=======================================================\n";

    showStreet (strts, streetCount);

    //Общая площадь всех участков
    float vilageArea = 0.0;
    float commonHouseArea = 0.0;
    float buildingsArea = 0.0;
    float commonBuildingsArea = 0.0;

    for (int i = 0; i < strts.size(); i++)
    {
        for (int j = 0; j < strts[i].sects.size(); j++)
        {
            commonHouseArea += strts[i].sects[j].hs.area;
            vilageArea += strts[i].sects[j].area;
            for (int k = 0; k < strts[i].sects[j].blds.size(); k++)
            {
                buildingsArea =+ strts[i].sects[j].blds[k].area;
            }

            commonBuildingsArea += (commonHouseArea + buildingsArea);
            std::cout << "commonSettArea = " << vilageArea << std::endl;
        }
    }



std::cout << "=======================================================\n";


    std::cout << "All houses area is = " << commonHouseArea;
    std::cout << "All buildings is = " << buildingsArea;
    std::cout << "Common buidings area is = " << commonBuildingsArea;

    std::cout << "Vilages area is = " << vilageArea << std::endl;

    float perscent = commonBuildingsArea/vilageArea * 100;
    std::cout << "The share of houses is " << perscent << "% of the area of the entire village";



    return 0;
}
