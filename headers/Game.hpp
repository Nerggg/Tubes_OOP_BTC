#ifndef __GAME_HPP
#define __GAME_HPP

// Libraries and STL
#include <iostream>
#include <vector>
#include <map>
#include <string>

// Header Files
#include "Item.hpp"
#include "Animal.hpp"
#include "Plant.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

using namespace std;

class Game {
    public:
        Game();

        friend class FileManager;

    private:
        static int GuldenWinAmount;
        static int WeightWinAmount;
};

class FileManager {
    public:
        static void readPlantData();
        static void readAnimalData();
        static void readProductData();
        static void readBuildingData();
        static void readMiscData();
        static void readPlayerData();
};

#endif