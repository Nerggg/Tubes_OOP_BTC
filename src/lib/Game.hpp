#ifndef __GAME_HPP
#define __GAME_HPP

// Libraries and STL
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

// Header Files
#include "colors.h"
#include "Item.hpp"
#include "Animal.hpp"
#include "Plant.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Store.hpp"
#include "SlowPrinter.hpp"

using namespace std;

class Game {
    friend class FileManager;
    public:
        Game();
        void Initialize();
        void Start();
};

class FileManager {
    public:
        static void readPlantData();
        static void readAnimalData();
        static void readProductData();
        static void readBuildingData();
        static void readMiscData();
        static void readPlayerData();

        static string getDirectories(string path);
        static void writePlayerData();
};

#endif