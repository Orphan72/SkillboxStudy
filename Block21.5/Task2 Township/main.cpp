#include <iostream>
#include <vector>

//TODO

// запись в файл?
// чтение из файла?

// создать функцию для рандомного заполнения

const int MINCOUTSTREET = 1;
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
    int buildlCount = 1;
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
    while (area > MINAREAROOM)
    {
        for (int m = flr.roomCount; m > 0; m--)
        {
            std::cout << "Enter name of room from " << LIVINGROOM << " to " << NURSERY << "\n";
            std::cout << LIVINGROOM << " - Garage\n" << BATHROOM << " - Bathhouse\n";
            std::cout << KITCHEN << " - Kitchen\n" << BEDROOM << " - Bedroom\n" << NURSERY << " - Nursery\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            flr.rm.name = (roomNames)3;// от 0 до количества в enum

            //str.sctn.hs.floor.rm.name = (roomNames)(4 - m + 1) ; // если по порядку

            std::cout << "Enter room's area from  " << MINAREAROOM;
            std::cout << " to " << area - MINAREAROOM * (float)(m - 1) << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            flr.rm.area = 12.0; // площадь не больше остатка площади этажа

            area -= flr.rm.area;

            std::cout << "Rest area flor is " << area << "\n=>";

            flr.rooms.push_back(flr.rm);
            if (area < MINAREAROOM) break;
        }
    }
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
        hs.floor.height = 2.0; //введите высоту потолков (от 2,5 до 4)

        std::cout << "Enter a count of room from " << MINCOUNTROOM << " to " << maxCountRoomFlor << "\n=>";
        hs.floor.roomCount = 4; //введите количество комнта (минимум 2, максимум 4)

        float areaRestFlor = hs.area;

        fullRoom(hs.floor, areaRestFlor);

        hs.flrs.push_back(hs.floor);
    }
}

void fullYard (section &sct, float area)
{
// остаток площади
    while (area >= MINAREABUILDING)
    {
        for (int k = sct.buildlCount; k > 0; k--)
        {
            std::cout << "Enter count of buildings from 0 to " << MINAREABUILDING;
            std::cout << " to " << area - MINAREABUILDING * (float) (k - 1) << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            sct.build.area = 20.0; // введите площадь строения (меньше, чем остсток площади, но больше чем 20)

            std::cout << "Enter one name of :\n";
            std::cout << "Enter name of building from " << GARAGE << " to " << BARN << "\n";
            std::cout << GARAGE << " - Garage " << BATHHOUSE << " - Bathhouse " << BARN << "- Barn\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            sct.build.name = BATHHOUSE; // от 0 до количества в enum

            (sct.build.name == BATHHOUSE) ? sct.build.stove = true : sct.build.stove = false;

            area -= sct.build.area;

            std::cout << "areaRestSect is " << area;

            sct.blds.push_back(sct.build);

            if (area < MINAREABUILDING)
                break;
        }
    }
}

void fullStreet (street &str, int n)
{

    for (int j = 0; j < str.sectionCount; j++) {
        str.sctn.number = n * str.sectionCount + j + 1;

        std::cout << "Enter section's area from " << MINAREASECTION << " to " << MAXAREASECTION << "\n=>";

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        str.sctn.area = 100.0; // введите площадь участка (от 100 до 1000)

        float areaSect = str.sctn.area;

        std::cout << "Enter hous' area from " << MINAREAHOUSE << " to " << areaSect * MAXSHARE << "\n=>";




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        str.sctn.hs.area = 50.0; // введите площадь дома (между 50 и площадью участка)

//float areaHouse = str.sctn.hs.area;
        float areaRestSect = areaSect - str.sctn.hs.area;
        int maxCountBuild = (areaRestSect) / MINAREABUILDING;

        std::cout << "Enter count of buildings from 0 to " << maxCountBuild << "\n=>";

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        str.sctn.buildlCount = 2;


        fullYard(str.sctn, areaRestSect);

        std::cout << "Enter count of floors from " << MINCOUTFLOR << " to " << MAXCOUTFLOR << "\n=>";

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        str.sctn.hs.florCount = 2; // введите количество этажей (от 1 до 3)



        std::cout << "Is there tube on the roof?\n=>";

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        str.sctn.hs.stove = true;// введите наличие трубы в доме


        fullStorey(str.sctn.hs);

//=============================================================
        str.sects.push_back(str.sctn);
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

        std::cout << "\t\t\Floor # " << flrs[i].num << " contains ";
        std::cout << flrs [i].roomCount << " rooms:\n";
        showRoom(flrs[i].rooms, flrs[i].roomCount);
        std::cout << "\t\tHeight or " << flrs[i].num << " fl. is " << flrs[i].height << " m\n";

    }
}






void showBuilding (std::vector <building> bls, int n)
{
    for (int i = 0; i < n; i++)
    {
        showBuildingName(bls [i].name);
        std::cout << bls [i].area << " sq.m";
        if (bls[i].stove == true)
        {
            std::cout << ", chimney on the roof\n";
        }
    }
}


void showHouse (house hs)
{

    std::cout << "\t\tArea " << hs.area << " sq. m, ";
    std::cout << hs.florCount << " fl.";
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
        std::cout << "Section # " << scts [i].number << "\n";
        std::cout << "\tArea: " << scts [i].area << "\n";
        std::cout << "\tHOUSE:\n";
        showHouse (scts[i].hs);
        //std::cout << "\tHous' area is " << scts [i].hs.area << "\n";
        std::cout << "\tBuildings:\n";
        showBuilding(scts[i].blds, scts[i].buildlCount);


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
    streetCount = 1;

    std::vector<street> strts;

    street str;

    for (int i = 0; i < streetCount; i++)
    {
        str.name = (streetNames)(i + 1);

        std::cout << "Enter count of section from " << MINCOUTSECTION << " to " << MAXCOUTSECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>
        str.sectionCount = 2;   // need enter

        fullStreet (str, i);


        strts.push_back(str);
    }

std::cout << "=======================================================\n";

    showStreet (strts, streetCount);


    return 0;
}
