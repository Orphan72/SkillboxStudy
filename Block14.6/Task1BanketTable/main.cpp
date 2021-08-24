#include <iostream>
#include <vector>

void display (std::vector<std::vector<std::string>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec [i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void displayChair (std::vector<std::vector<bool>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec [i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void displayVipChair (std::vector<bool> vec){
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec [i] << " ";
    }
        std::cout << std::endl;
}

int main() {

    const int ROW         = 2;
    const int ECONOM      = 5;
    const int VIP         = 2;
    const int CULTERY     = 3;
    const int VIPCULTERY  = 4;
    const int PLATE       = 2;
    const int VIPPLATE    = 3;

    const int PLACE = 3;
    int place = ECONOM - 1 + PLACE;

    std::vector <std::vector<std::string>> econCultery (ECONOM*ROW, std::vector<std::string> (CULTERY));
    std::vector <std::vector<std::string>> econPlate (ECONOM*ROW, std::vector<std::string> (PLATE));
    std::vector <std::vector<std::string>> vipCultery (VIP, std::vector<std::string> (VIPCULTERY));
    std::vector <std::vector<std::string>> vipPlate (VIP, std::vector<std::string> (VIPPLATE));

    std::vector <std::vector<bool>> econChair (ROW, std::vector<bool> (ECONOM));
    std::vector <bool> vipChair (VIP);

    for (int i = 0; i < econCultery.size(); i++) {
        econCultery [i] = {"spoon", "fork", "knife"};
    }

    for (int i = 0; i < econPlate.size(); i++) {
        econPlate [i] = {"firstPlate", "secPlate"};
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

   std::cout << "\n===========\nExtra chair was added:\n";
   econChair[1].push_back(true);

   displayChair (econChair);

   std::cout << "\n===========\nThe spoon was gone:\n";
   for (int i = 0; i < econCultery[place].size() - 1; i++) {
        econCultery [place][i] = econCultery [place][i + 1];
    }
    econCultery [place].pop_back();

    display (econCultery);

    std::cout << "\n===========\nThe VIP person share his spoon:\n";

    for (int i = 0; i < vipCultery[0].size() - 1 ; i++) {
        vipCultery [0][i] = vipCultery [0][i + 1];
    }
    vipCultery [0].pop_back();

    econCultery[place].resize(econCultery[place].size() + 1);
    for (int i = econCultery[place].size() - 1; i > 0; i--) {
        econCultery [place][i] = econCultery [place][i - 1];
    }
    econCultery [place][0] = "spoon";

    display (econCultery);
    display (vipCultery);

    std::cout << "\n===========\nThe desert plate was take away:\n";
    vipPlate [0].pop_back();

    display (vipPlate);

    return 0;
}
