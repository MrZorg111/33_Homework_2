#pragma once
#include <iostream>

void game_map() {
    int count_fild(0);
    for(int higth(0); higth < 27; higth++) {
        for (int weigth(0); weigth < 19; weigth++) {
            if(higth == 0 || higth == 8 || higth == 17 || higth == 26) {
                std::cout << "---";
            }
            
            else if((higth != 0 && higth != 8 && higth != 17 && higth != 26) && (weigth == 0 || weigth == 6 || weigth == 12 || weigth == 18)) {
                if (weigth == 18) {
                    std::cout << "  |";
                }
                else {
                    std::cout << "|  ";
                }
            }
            else {
                if ((higth == 4 || higth == 13 || higth == 22) && (weigth == 2 || weigth == 8 || weigth == 15)) {
                    count_fild += 1;
                    std::cout << "  " << count_fild;
                }
                else {
                    std::cout << "   ";
                }
            }
        }
        std::cout << std::endl;
    }
}