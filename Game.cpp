#include "headers/Game.hpp"
#include <sstream>

// Static Attributes
int Game::GuldenWinAmount;
int Game::WeightWinAmount;

Game::Game() {
    FileManager::readPlantData();
    FileManager::readAnimalData();
    FileManager::readProductData();
    FileManager::readBuildingData();
    FileManager::readMiscData();

    // for (const auto& pair: Plant::getPlantData()) {
    //     cout << pair.second;
    // }

    // for (const auto& pair : Animal::getAnimalData()) {
    //     cout << pair.second;
    // }

    // for (const auto& pair : Product::getProductData()) {
    //     cout << *pair.second;
    // }

    // for (const auto& pair : Building::getBuildingData()) {
    //     cout << *pair.second;

    // cout << Game::GuldenWinAmount << endl;
    // cout << Game::WeightWinAmount << endl;
    // cout << Inventory::InventoryRows << " " << Inventory::InventoryCols<< endl;
    // cout << Farm::FarmRows << " " << Farm::FarmCols << endl;
    // cout << Barn::BarnRows << " " << Barn::BarnCols << endl;
}

// ========================================================
// =================== readPlantData ======================
// ========================================================

void FileManager::readPlantData() {
    ifstream file("./config/plant.txt");
    string line;

    while (getline(file, line, ' ')) {
        Plant* x = new Plant();

        // Get Item ID
        x->id = stoi(line);

        // Get Item code
        getline(file, x->code, ' ');

        // Get Item name
        getline(file, x->name, ' ');

        // Get Item type
        getline(file, x->type, ' ');

        // Get Plant harvestAge
        getline(file, line, ' ');
        x->harvestAge = stoi(line);
        
        // Get Item price
        getline(file, line);
        x->price = stoi(line);

        // Append Plant to PlantData
        Plant::PlantData.insert(make_pair(x->name, x));
    }
}

// ========================================================
// ================== readAnimalData ======================
// ========================================================

void FileManager::readAnimalData() {
    ifstream file("./config/animal.txt");
    string line;

    while (getline(file, line, ' ')) {
        int id; string code; string name; string type; int harvestWeight; int price; 

        // Get Animal ID
        id = stoi(line);

        // Get Animal code
        getline(file, code, ' ');

        // Get Animal name
        getline(file, name, ' ');

        // Get Animal type
        getline(file, type, ' ');

        // Get Animal harvestWeight
        getline(file, line, ' ');
        harvestWeight = stoi(line);
        
        // Get Animal price
        getline(file, line);
        price = stoi(line);

        // Type checking
        Animal* x;
        if (type == TYPE_HERBIVORE) {
            x = new Herbivore(id, code, name, type, harvestWeight, price, "Animal");
        } else if (type == TYPE_CARNIVORE) {
            x = new Carnivore(id, code, name, type, harvestWeight, price, "Animal");
        } else {
            x = new Omnivore(id, code, name, type, harvestWeight, price, "Animal");
        }
        
        // Append Animal to AnimalData
        Animal::AnimalData.insert(make_pair(x->name, x));
    }
}

// ========================================================
// ================== readProductData =====================
// ========================================================

void FileManager::readProductData() {
    ifstream file("./config/product.txt");
    string line;

    while (getline(file, line, ' ')) {
        Product* x = new Product();

        // Get Product ID
        x->id = stoi(line);

        // Get Product code
        getline(file, x->code, ' ');

        // Get Product name
        getline(file, x->name, ' ');

        // Get Product type
        getline(file, x->type, ' ');

        // Get Product origin
        getline(file, x->origin, ' ');
        
        // Get Product addedWeight
        getline(file, line, ' ');
        x->addedWeight = stoi(line);

        // Get Product price
        getline(file, line);
        x->price = stoi(line);

        // Append Product to ProductData
        Product::ProductData.insert(make_pair(x->name, x));
    }
}

// ========================================================
// ================== readBuildingData ====================
// ========================================================

void FileManager::readBuildingData() {
    ifstream file("./config/recipe.txt");
    string line;

    while (getline(file, line, ' ')) {
        Building* x = new Building();

        // Get Building ID
        x->id = stoi(line);

        // Get Building code
        getline(file, x->code, ' ');

        // Get Building name
        getline(file, x->name, ' ');

        // Set Building type as blank
        x->type = "";

        // Get Building price
        getline(file, line, ' ');
        x->price = stoi(line);

        // Get Building recipe
        map<string, int> recipe;
        getline(file, line);
        stringstream str_stream(line);

        string first;
        string second;
        while(getline(str_stream, first, ' ')) {
            getline(str_stream, second, ' ');
            recipe.insert(make_pair(first, stoi(second)));

            // cout << first << " " <<  second << endl;
        }

        x->recipe = recipe;

        // Append Building to ProductData
        Building::BuildingData.insert(make_pair(x->name, x));
    }
}

// ========================================================
// ==================== readMiscData ======================
// ========================================================

void FileManager::readMiscData() {
    ifstream file("./config/misc.txt");
    string line;

    // Get GuldenWinAmount
    getline(file, line);
    Game::GuldenWinAmount = stoi(line);

    // Get WeightWinAmount
    getline(file, line);
    Game::WeightWinAmount = stoi(line);

    // Get StorageRows and StorageCols
    getline(file, line, ' ');
    Inventory::InventoryRows = stoi(line);
    
    getline(file, line);
    Inventory::InventoryCols = stoi(line);
    
    // Get FarmRows and FarmCols
    getline(file, line, ' ');
    Farm::FarmRows = stoi(line);
    
    getline(file, line);
    Farm::FarmCols = stoi(line);

    // Get BarnRows and BarnCols
    getline(file, line, ' ');
    Barn::BarnRows = stoi(line);
    
    getline(file, line);
    Barn::BarnCols = stoi(line);

}