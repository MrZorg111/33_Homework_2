#pragma once
#include <vector>
#include <ctime>
#include <execution>

std::vector<std::string> crystal_lake(9);

class Fish: public std::exception {
    const char* what() const noexcept override {
        return "Congratulations!";
    } 
};
class Boot: public std::exception {
    const char* what() const noexcept override {
        return "You've caught the boot! Defeat!";
    }
};
int randomaizer(int random_volume) {
    srand(std::time(nullptr));
    return rand() % random_volume;
}
void fish_load() {
    std::string boot("Boot"), fish("Fish");
    int sector_lake(0);

    for(int i = 0; i < 9;) {
        sector_lake = randomaizer(9);
        if(crystal_lake[sector_lake].empty()) {
            if(i < 3) {
                crystal_lake[sector_lake] = boot;
                i++;
            }
            else if(i == 3) {
                crystal_lake[sector_lake] = fish;
                i++;
            }
            else {
                i++;
            }

        }
    }
}
void game_actor() {
    int fild_num(0), count_try(1), start_timer(std::time(nullptr));
    int timer = start_timer;
    
    for(;;) {
        std::cout << "Enter the number of the field into which we will cast the fishing rod: " << std::endl;
        std::cin >> fild_num;
        fild_num -= 1;
    
    
        std::cout << "START FISHING";
        for(int i = 0; i < 3; ) {
            if (timer > start_timer) {
                std::cout << ".";
                start_timer = timer;
                i++;
            }
            timer = std::time(nullptr);
        }
        if (crystal_lake[fild_num] == "Fish") {
            std::cerr << "You caught a fish with " << count_try << " attempts!" << std::endl;
            throw Fish();
        }
        else if(crystal_lake[fild_num] == "Boot") {
            throw Boot();
        }
        else {
            std::cout << "You haven't caught anything, let's cast the bait again!" << std::endl;
            count_try++;
            continue;
        }
    }
}

