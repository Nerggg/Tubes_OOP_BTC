#include "lib/Game.hpp"

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

        // Append Plant to ItemData
        Item::ItemData[x->name] = x;
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
            x = new Herbivore(id, code, name, type, harvestWeight, price);
        } else if (type == TYPE_CARNIVORE) {
            x = new Carnivore(id, code, name, type, harvestWeight, price);
        } else {
            x = new Omnivore(id, code, name, type, harvestWeight, price);
        }
        
        // // Append Animal to AnimalData
        Animal::AnimalData.insert(make_pair(x->name, x));

        // Append Animal to ItemData
        Item::ItemData[x->name] = x;
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

        // // Append Product to ProductData
        // Product::ProductData.insert(make_pair(x->name, x));

        // Append Product to ItemData
        Item::ItemData[x->name] = x;
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

        // // Append Building to ProductData
        // Building::BuildingData.insert(make_pair(x->name, x));

        // Append Building to ItemData
        Item::ItemData[x->name] = x;
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
    Player::GuldenWinAmount = stoi(line);

    // Get WeightWinAmount
    getline(file, line);
    Player::WeightWinAmount = stoi(line);

    // Get StorageRows and StorageCols
    getline(file, line, ' ');
    InventoryContainer::InventoryRows = stoi(line);
    
    getline(file, line);
    InventoryContainer::InventoryCols = stoi(line);
    
    // Get FarmRows and FarmCols
    getline(file, line, ' ');
    InventoryContainer::FarmRows = stoi(line);
    
    getline(file, line);
    InventoryContainer::FarmCols = stoi(line);

    // Get BarnRows and BarnCols
    getline(file, line, ' ');
    InventoryContainer::BarnRows = stoi(line);
    
    getline(file, line);
    InventoryContainer::BarnCols = stoi(line);

}

// ========================================================
// =================== readPlayerData =====================
// ========================================================

void FileManager::readPlayerData() {
    ifstream file("./save/state.txt");
    string line;

    // Get number of players
    getline(file, line);
    int n_players = stoi(line);

    // Get player data
    for (int i = 0; i < n_players; i++) {
        // Get player name
        getline(file, line, ' ');
        string name = line;

        // Get player type
        getline(file, line, ' ');
        string type = line;

        // Get player weight
        getline(file, line, ' ');
        int weight = stoi(line);

        // Get player money
        getline(file, line);
        int money = stoi(line);

        // Decide player type
        Player* x;
        if (type == TYPE_WALIKOTA) {
            x = new Walikota(name, weight, money);
        } else if (type == TYPE_PETANI) {
            x = new Petani(name, weight, money);
        } else {
            x = new Peternak(name, weight, money);
        }

        // Get player inventory
        getline(file, line);
        int n_inventory = stoi(line);

        // Get items
        for (int j = 0; j < n_inventory; j++) {
            // Get item name
            getline(file, line);
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            string item_name = line;

            // Copy item
            Item* item = Item::ItemData[item_name]->clone();

            // Insert to player inventory
            x->insertToInventory(item);
        }

        // If Player = Peternak, get barn data
        if (type == TYPE_PETERNAK) {
            // Get animal count
            getline(file, line);
            int n_animal = stoi(line);

            // Get animals
            for (int j = 0; j < n_animal; j++) {
                // Get animal position
                getline(file, line, ' ');
                string pos = line;
                
                // Get animal name
                getline(file, line, ' ');
                line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
                string item_name = line;

                // Get animal weight
                getline(file, line);
                int weight = stoi(line);

                // Copy item
                Animal* item = (Animal*) Item::ItemData[item_name]->clone();
                item->weight = weight;

                // Insert to player barn
                x->insertToBarn(item, pos);
            }
        }

        // If Player = Petani, get farm data
        if (type == TYPE_PETANI) {
            // Get plant count
            getline(file, line);
            int n_plant = stoi(line);

            // Get plants
            for (int j = 0; j < n_plant; j++) {
                // Get plant position
                getline(file, line, ' ');
                string pos = line;
                
                // Get plant name
                getline(file, line, ' ');
                line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
                string item_name = line;

                // Get plant age
                getline(file, line);
                int age = stoi(line);

                // Copy item
                Plant* item = (Plant*) Item::ItemData[item_name]->clone();
                item->age = age;

                // Insert to player farm
                x->insertToFarm(item, pos);
            }
        }

        // Insert player to PlayerData
        Player::PlayerData[name] = x;
    }

    // Get store data
    // Get number of store items
    getline(file, line);
    int n_store = stoi(line);

    // Get store items
    for (int i = 0; i < n_store; i++) {
        // Get item name
        getline(file, line, ' ');
        string item_name = line;

        // Get item count
        getline(file, line);
        int count = stoi(line);

        // Insert to store
        Store::StoreData[item_name] = count;
    }
}