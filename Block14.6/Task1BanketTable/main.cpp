#include <iostream>
#include <vector>


void display (std::vector<std::vector<std::string>> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec [i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void displayChair (std::vector<std::vector<bool>> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec [i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void displayVipChair (std::vector<bool> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec [i] << " ";
    }
        std::cout << std::endl;
}




int main() {

    const int ROW      = 2;
    const int ECONOM   = 5;
    const int VIP      = 2;
    const int ECCULT   = 3;
    const int VIPCULT  = 4;
    const int ECPLATE  = 2;
    const int VIPPLATE = 3;

    std::vector <std::vector<std::string>> econCultery (ECONOM*ROW, std::vector<std::string> (ECCULT));
    std::vector <std::vector<std::string>> econPlate (ECONOM*ROW, std::vector<std::string> (ECPLATE));
    std::vector <std::vector<std::string>> vipCultery (VIP, std::vector<std::string> (VIPCULT));
    std::vector <std::vector<std::string>> vipPlate (VIP, std::vector<std::string> (VIPPLATE));

    std::vector <std::vector<bool>> econChair (ROW, std::vector<bool> (ECONOM));
    std::vector <bool> vipChair (VIP);

    for (int i = 0; i < econCultery.size(); i++) {
        econCultery [i] = {"spoon", "fork", "knife"};
    }

    for (int i = 0; i < econPlate.size(); i++) {
        econPlate [i] = {"plateOne", "plateSec"};
    }

    for (int i = 0; i < vipCultery.size(); i++) {
        vipCultery [i] = {"spoon", "fork", "knife", "desSpoon"};
    }

    for (int i = 0; i < vipPlate.size(); i++) {
        vipPlate [i] = {"firstPlate", "sesPlate", "desPlate"};
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < ECONOM; j++) {
                econChair [i][j] = true;
        }
    }

    for (int i = 0; i < VIP; i++) {
        vipChair [i] = true;
    }

   display (econCultery);
   display (econPlate);
   display (vipCultery);
   display (vipPlate);
   displayChair (econChair);
   displayVipChair (vipChair);


    /*

    По поводу успешного прохождения двумерных массивов собирается банкет, организуется стол на 12 персон, 2 из них - это места VIP,
    они расположены рядом друг к другу во главе стола. Стол протяжённый в длину, места расположены в два ряда.
    Каждый пришедший должен быть “упакован” соответствующим образом. Во-первых столовые приборы - их три на каждого человека (вилка, ложка, нож),
    плюс одна маленькая дополнительная ложечка для VIP-персон, для десерта.
    Это необходимо обеспечить. Следом тарелки, каждому по две - для первого и второго блюда, для VIP персон +1 тарелка для десерта.
    Ну и конечно стул - один для каждого, минимум! Заведите соответствующие двумерные массивы для количества приборов,
    посуды и стульев и проинициализируйте их как следует.

            Однако, это ещё не всё. В ходе банкета, уже после инициализации, происходят некоторые события.
            Пришедшая на 5-ое место первого ряда дама пришла вместе с ребёнком и поэтому на данное место был приставлен ещё один стул.
            С третьего места во втором ряду в неизвестном направлении была украдена ложка.
            После этого одна из VIP персон (любая) поделилась своей ложкой с тем у кого она пропала, а сам стал есть суп десертной.
            За ненадобностью официант забрал у него одну десертную тарелку, ибо есть десерт ложкой, которая побывала уже в супе - не комильфо.
            Больше без происшествий!

  */

    return 0;
}
