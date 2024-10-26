#include <iostream>
#include "function.h"
#include "game_map.h"
#include <exception>


int main() {
    std::cout << "The playing field: " << std::endl;
    game_map();
    fish_load();
    try{
        game_actor();
    }
    catch (const Fish()) {}
    catch (Boot()) {}
    return 0;
}