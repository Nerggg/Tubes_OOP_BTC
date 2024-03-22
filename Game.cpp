#include "headers/Game.hpp"
#include <typeinfo>

// Static Attributes

Game::Game() {
    FileManager::readPlantData();
    FileManager::readAnimalData();

    for (auto plant : Plant::getPlantData()) {
        cout << *plant;
    }

    for (auto animal : Animal::getAnimalData()) {
        cout << *animal;
    }
}

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
        Plant::PlantData.push_back(x);
    }
}

void FileManager::readAnimalData() {
    ifstream file("./config/animal.txt");
    string line;

    while (getline(file, line, ' ')) {
        int id; string code; string name; string type; int harvestWeight; int price; 

        // Get Item ID
        id = stoi(line);

        // Get Item code
        getline(file, code, ' ');

        // Get Item name
        getline(file, name, ' ');

        // Get Item type
        getline(file, type, ' ');

        // Get Animal harvestWeight
        getline(file, line, ' ');
        harvestWeight = stoi(line);
        
        // Get Item price
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
        Animal::AnimalData.push_back(x);
    }
}