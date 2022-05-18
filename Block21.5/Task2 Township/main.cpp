#include <iostream>
#include <vector>
#include <ctime>

//TODO

// протестить
// создать функцию для рандомного заполнения

const int MINCOUNTSTREET = 1;
const int MAXCOUNTSTREET = 4;

const int MINCOUNTSECTION = 1;
const int MAXCOUNTSECTION = 5;

const int MAXCOUNTBUILDING = 4;

const int MINCOUNTFLOR = 1;
const int MAXCOUNTFLOR = 3;

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
    RECNAYA
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
    float comBuildArea = 0.0;
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
   for (int m = flr.roomCount; m > 0; m--)
   {
        std::cout << "Enter name of room from " << LIVINGROOM << " to " << NURSERY << "\n";
        std::cout << LIVINGROOM << " - Livingroom\n" << BATHROOM << " - Bathroom\n";
        std::cout << KITCHEN << " - Kitchen\n" << BEDROOM << " - Bedroom\n" << NURSERY << " - Nursery\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> nm;
        int diffNm = NURSERY - LIVINGROOM;
        nm = std::rand()%(diffNm + 1) + LIVINGROOM;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
        flr.rm.name = (roomNames)nm;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        std::cout << "Enter room's area from  " << MINAREAROOM;
        std::cout << " to " << area - MINAREAROOM * (float)(m - 1) << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> flr.rm.area;
        int diffAr = (area - MINAREAROOM * (float)(m - 1)) - MINAREAROOM;
        flr.rm.area = std::rand()%(diffAr + 1) + MINAREAROOM;

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        area -= flr.rm.area;
        std::cout << "Rest area flor is " << area << "\n";

        flr.rooms.push_back(flr.rm);
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

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> hs.floor.height;
        int diffHght = MAXHEIGHTFLOOR - MINHEIGHTFLOOR;
        hs.floor.height = std::rand()%(diffHght + 1) + MINHEIGHTFLOOR;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        std::cout << "Enter a count of room from " << MINCOUNTROOM << " to " << maxCountRoomFlor << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> hs.floor.roomCount;
        int diffRoomCount = maxCountRoomFlor - MINCOUNTROOM;
        hs.floor.roomCount = std::rand()% (diffRoomCount + 1) + MINCOUNTROOM;

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        float areaRestFlor = hs.area;

        fullRoom(hs.floor, areaRestFlor);

        hs.flrs.push_back(hs.floor);
        hs.floor.rooms.clear();
    }
}

void fullYard (section &sct, float area)
{
    int nm = 0;

        for (int k = sct.buildlCount; k > 0; k--)
        {
            std::cout << "Enter buildings area from " << MINAREABUILDING;
            std::cout << " to " << area - MINAREABUILDING * (float) (k - 1) << "\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            //std::cin >> sct.build.area;
            int diffBldArea = (area - MINAREABUILDING * (float) (k - 1)) - MINAREABUILDING;
            sct.build.area = std::rand()%(diffBldArea + 1) + MINAREABUILDING;

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            sct.comBuildArea += sct.build.area;

            std::cout << "Enter name of building from " << GARAGE << " to " << BARN << "\n";
            std::cout << GARAGE << " - Garage " << BATHHOUSE << " - Bathhouse " << BARN << "- Barn\n=>";

            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            //std::cin >> nm;
            int diffNm = BARN - GARAGE;
            nm = std::rand()%(diffNm + 1) + GARAGE;

            sct.build.name = (buildNames)nm;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

            sct.build.stove = (sct.build.name == BATHHOUSE);

            area -= sct.build.area;

            std::cout << "areaRestSect is " << area << std::endl;
            sct.blds.push_back(sct.build);
        }
}

void fullStreet (street &str, int n)
{

    for (int j = 0; j < str.sectionCount; j++) {
        str.sctn.number = n*MAXCOUNTSTREET + j + 1;

        std::cout << "Enter section's area from " << MINAREASECTION << " to " << MAXAREASECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> str.sctn.area;
        int diffSectAr = MAXAREASECTION - MINAREASECTION;
        str.sctn.area = std::rand()%(diffSectAr + 1) + MINAREASECTION;

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        float areaSect = str.sctn.area;

        std::cout << "Enter hous' area from " << MINAREAHOUSE << " to " << areaSect * MAXSHARE << "\n=>";

       //>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> str.sctn.hs.area;
        int diffHsAr = areaSect * MAXSHARE - MINAREAHOUSE;
        str.sctn.hs.area = std::rand()%(diffHsAr + 1) + MINAREAHOUSE;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        float areaRestSect = areaSect - str.sctn.hs.area;
        //int maxCountBuild = (areaRestSect) / MINAREABUILDING;

        std::cout << "Enter count of buildings from 0 to " << MAXCOUNTBUILDING << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> str.sctn.buildlCount;
        str.sctn.buildlCount = std::rand()%(MAXCOUNTBUILDING + 1);

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        if (str.sctn.buildlCount)
        {
            fullYard(str.sctn, areaRestSect);
        }



        std::cout << "Enter count of floors from " << MINCOUNTFLOR << " to " << MAXCOUNTFLOR << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> str.sctn.hs.florCount;
        int diffCntFl = MAXCOUNTFLOR - MINCOUNTFLOR;
        str.sctn.hs.florCount = std::rand()%(diffCntFl + 1) + MINCOUNTFLOR;

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        std::cout << "Is there tube on the roof?\n";
        std::cout << "1 - tube is\n0 - tube is not\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //std::cin >> str.sctn.hs.stove;
        str.sctn.hs.stove = std::rand()%2;

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        fullStorey(str.sctn.hs);

        str.sects.push_back(str.sctn);
        str.sctn.hs.flrs.clear ();
        str.sctn.blds.clear();
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
        std::cout << "\t\t\tNumber of floors: " << scts[i].hs.florCount;

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
    std::cout << "Do you want to fill data automatically or manually?";


    std::cout << "Enter count of street from " << MINCOUNTSTREET << " to " << MAXCOUNTSTREET << "\n=>";

    //>>>>>>>>>>>>>>>>>>>>>>
    //std::cin >> streetCount;
    int diffStrCount = MAXCOUNTSTREET - MINCOUNTSTREET;
    streetCount = std::rand()%(diffStrCount + 1) + MINCOUNTSTREET;

    //>>>>>>>>>>>>>>>>>>>>>>




    std::vector<street> strts;



    for (int i = 0; i < streetCount; i++)
    {
        street str;
        str.name = (streetNames)(i + 1);

        std::cout << "Enter count of section from " << MINCOUNTSECTION << " to " << MAXCOUNTSECTION << "\n=>";

        //>>>>>>>>>>>>>>>>>>>>>>
        std::cin >> str.sectionCount;
        //int diffSectCount = MAXCOUNTSECTION - MINCOUNTSECTION;
        //str.sectionCount = std::rand()%(diffSectCount + 1) + MINCOUNTSECTION;

        //>>>>>>>>>>>>>>>>>>>>>>


        fullStreet (str, i);

        strts.push_back(str);
    }

std::cout << "=======================================================\n";

    showStreet (strts, streetCount);

    //Общая площадь всех участков
    float vilageArea = 0.0;
    float commonHouseArea = 0.0;
    float commonBuildingsArea = 0.0;




    for (int i = 0; i < strts.size(); i++)
    {
        for (int j = 0; j < strts[i].sects.size(); j++)
        {
            commonHouseArea += strts[i].sects[j].hs.area;
            vilageArea += strts[i].sects[j].area;
            for (int k = 0; k < strts[i].sects[j].blds.size(); k++)
            {
                commonBuildingsArea += strts[i].sects[j].blds[k].area;
            }



        }
    }






std::cout << "=======================================================\n";

    std::cout << "Vilages area is " << vilageArea << std::endl;
    std::cout << "Area of all houses is " << commonHouseArea << std::endl;
    std::cout << "Area of all buildings is " << commonBuildingsArea << std::endl;

    float perscent = (commonHouseArea + commonBuildingsArea)/vilageArea * 100;

    std::cout << "The share of all houses and buildings is " << perscent << "% of the area of the entire village";

    return 0;
}
