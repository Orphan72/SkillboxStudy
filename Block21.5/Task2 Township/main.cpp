#include <iostream>
#include <vector>
#include <ctime>

const int MINCOUNTSTREET = 1;
const int MAXCOUNTSTREET = 3;

const int MINCOUNTSECTION = 1;
const int MAXCOUNTSECTION = 2;

const int MAXCOUNTBUILDING = 4;

const int MINCOUNTFLOR = 1;
const int MAXCOUNTFLOR = 3;

const int MINCOUNTROOM = 2;
const int MAXCOUNTROOM = 4;

const float MINAREASECTION = 100.0;
const float MAXAREASECTION = 500.0;

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

void fullRoom (storey &flr, float area, bool rndm)
{
   int nm = 0;
   for (int m = flr.roomCount; m > 0; m--)
   {
       if (rndm)
       {
           int diffNm = NURSERY - LIVINGROOM;
           nm = std::rand()%(diffNm + 1) + LIVINGROOM;

           int diffAr = (area - MINAREAROOM * (float)(m - 1)) - MINAREAROOM;
           flr.rm.area = std::rand()%(diffAr + 1) + MINAREAROOM;
       }
       else
       {
           std::cout << "Enter name of room from " << LIVINGROOM << " to " << NURSERY << "\n";
           std::cout << LIVINGROOM << " - Livingroom\n" << BATHROOM << " - Bathroom\n";
           std::cout << KITCHEN << " - Kitchen\n" << BEDROOM << " - Bedroom\n" << NURSERY << " - Nursery\n=>";
           std::cin >> nm;

           std::cout << "Enter room's area from  " << MINAREAROOM;
           std::cout << " to " << area - MINAREAROOM * (float)(m - 1) << "\n=>";
           std::cin >> flr.rm.area;
       }
       flr.rm.name = (roomNames)nm;

       area -= flr.rm.area;
       flr.rooms.push_back(flr.rm);
   }
}

void fullStorey (house &hs, bool rndm)
{
    int maxCountRoomFlor = hs.area/MINAREAROOM;

    if (maxCountRoomFlor > MAXCOUNTROOM)
        maxCountRoomFlor = MAXCOUNTROOM;

    for (int l = 0; l < hs.florCount; l++)
    {
        hs.floor.num = l + 1;

        if (rndm)
        {
            int diffHght = MAXHEIGHTFLOOR - MINHEIGHTFLOOR;
            hs.floor.height = std::rand()%(diffHght + 1) + MINHEIGHTFLOOR;

            int diffRoomCount = maxCountRoomFlor - MINCOUNTROOM;
            hs.floor.roomCount = std::rand()% (diffRoomCount + 1) + MINCOUNTROOM;
        }
        else
        {
            std::cout << "Enter a height of floor from " << MINHEIGHTFLOOR << " to " << MAXHEIGHTFLOOR << "\n=>";
            std::cin >> hs.floor.height;
            std::cout << "Enter a count of room from " << MINCOUNTROOM << " to " << maxCountRoomFlor << "\n=>";
            std::cin >> hs.floor.roomCount;
        }

        float areaRestFlor = hs.area;

        fullRoom(hs.floor, areaRestFlor, rndm);

        hs.flrs.push_back(hs.floor);
        hs.floor.rooms.clear();
    }
}

void fullYard (section &sct, float area, bool rndm)
{
    int nm = 0;

        for (int k = sct.buildlCount; k > 0; k--)
        {
            if (rndm)
            {
                int diffBldArea = (area - MINAREABUILDING * (float) (k - 1)) - MINAREABUILDING;
                sct.build.area = std::rand()%(diffBldArea + 1) + MINAREABUILDING;

                int diffNm = BARN - GARAGE;
                nm = std::rand()%(diffNm + 1) + GARAGE;
            }
            else
            {
                std::cout << "Enter buildings area from " << MINAREABUILDING;
                std::cout << " to " << area - MINAREABUILDING * (float) (k - 1) << "\n=>";
                std::cin >> sct.build.area;
                std::cout << "Enter name of building from " << GARAGE << " to " << BARN << "\n";
                std::cout << GARAGE << " - Garage " << BATHHOUSE << " - Bathhouse " << BARN << "- Barn\n=>";
                std::cin >> nm;
            }

            sct.comBuildArea += sct.build.area;
            sct.build.name = (buildNames)nm;
            sct.build.stove = (sct.build.name == BATHHOUSE);
            area -= sct.build.area;

            sct.blds.push_back(sct.build);
        }
}

void fullStreet (street &str, int n, bool rndm)
{
    float areaSect = 0.0;
    float areaRestSect = 0.0;
    int maxCountBuild = 0;

    for (int j = 0; j < str.sectionCount; j++)
    {
        str.sctn.number = n*MAXCOUNTSTREET + j + 1;

        if (rndm)
        {
            int diffSectAr = MAXAREASECTION - MINAREASECTION;
            str.sctn.area = std::rand()%(diffSectAr + 1) + MINAREASECTION;

            areaSect = str.sctn.area;
            int diffHsAr = areaSect * MAXSHARE - MINAREAHOUSE;
            str.sctn.hs.area = std::rand()%(diffHsAr + 1) + MINAREAHOUSE;

            areaRestSect = areaSect - str.sctn.hs.area;
            maxCountBuild = (areaRestSect) / MINAREABUILDING;
            if (maxCountBuild > MAXCOUNTBUILDING) maxCountBuild = MAXCOUNTBUILDING;

            str.sctn.buildlCount = std::rand()%(maxCountBuild + 1);

            int diffCntFl = MAXCOUNTFLOR - MINCOUNTFLOR;
            str.sctn.hs.florCount = std::rand()%(diffCntFl + 1) + MINCOUNTFLOR;

            str.sctn.hs.stove = std::rand()%2;
        }
        else
        {
            std::cout << "Enter section's area from " << MINAREASECTION << " to " << MAXAREASECTION << "\n=>";
            std::cin >> str.sctn.area;

            areaSect = str.sctn.area;
            std::cout << "Enter hous' area from " << MINAREAHOUSE << " to " << areaSect * MAXSHARE << "\n=>";
            std::cin >> str.sctn.hs.area;

            areaRestSect = areaSect - str.sctn.hs.area;
            maxCountBuild = (areaRestSect) / MINAREABUILDING;
            if (maxCountBuild > MAXCOUNTBUILDING) maxCountBuild = MAXCOUNTBUILDING;

            std::cout << "Enter count of buildings from 0 to " << maxCountBuild << "\n=>";
            std::cin >> str.sctn.buildlCount;

            std::cout << "Enter count of floors from " << MINCOUNTFLOR << " to " << MAXCOUNTFLOR << "\n=>";
            std::cin >> str.sctn.hs.florCount;

            std::cout << "Is there tube on the roof?\n";
            std::cout << "1 - tube is\n0 - tube is not\n=>";
            std::cin >> str.sctn.hs.stove;
        }

        if (str.sctn.buildlCount)
        {
            fullYard(str.sctn, areaRestSect, rndm);
        }

        fullStorey(str.sctn.hs, rndm);

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
    if (hs.stove)
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
    std::srand(std::time(nullptr));
    int streetCount = 0;
    bool random = false;
    std::cout << "Do you want to fill data manually or automatically?\n 0 - manualy\n 1 - automatically\n";
    std::cin >> random;

    if (random)
    {
        int diffStrCount = MAXCOUNTSTREET - MINCOUNTSTREET;
        streetCount = std::rand()%(diffStrCount + 1) + MINCOUNTSTREET;
    }
    else
    {
        std::cout << "Enter count of street from " << MINCOUNTSTREET << " to " << MAXCOUNTSTREET << "\n=>";
        std::cin >> streetCount;
    }

    std::vector<street> strts;

    for (int i = 0; i < streetCount; i++)
    {
        street str;
        str.name = (streetNames)(i + 1);
        if (random)
        {
            int diffSectCount = MAXCOUNTSECTION - MINCOUNTSECTION;
            str.sectionCount = std::rand()%(diffSectCount + 1) + MINCOUNTSECTION;
        }
        else
        {
            std::cout << "Enter count of section from " << MINCOUNTSECTION << " to " << MAXCOUNTSECTION << "\n=>";
            std::cin >> str.sectionCount;
        }

        fullStreet (str, i, random);
        strts.push_back(str);
    }

std::cout << "=======================================================\n";

    showStreet (strts, streetCount);

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
