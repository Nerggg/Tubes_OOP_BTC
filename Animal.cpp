#include "headers/Animal.hpp"

// Static Attribute
vector<Animal*> Animal::AnimalData;

// ========================================================
// ====================== Animal ==========================
// ========================================================

Animal::Animal() : Item() {
    this->harvestWeight = 0;
    this->weight = 0;
}

Animal::Animal(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestWeight, 
    int price, 
    string itemType
) : Item(id, code, name, type, price, itemType) {
    this->harvestWeight = harvestWeight;
    this->weight = 0;
}

ostream& operator<<(ostream& out, Animal x) {
    out << "ID: "           << x.id    << endl;
    out << "Animal Code: "  << x.code  << endl;
    out << "Animal Name: "  << x.name  << endl;
    out << "Animal Type: "  << x.type  << endl;
    out << "Animal Weight: "   << x.weight  << endl;
    out << "Animal Harvest Weight: " << x.harvestWeight << endl;
    out << "Animal Price: " << x.price << endl;
    out << endl;

    return out;
}

void Animal::feed(Item t) {
    cout << "Animal eating..." << endl;
}

// ========================================================
// ===================== Herbivore ========================
// ========================================================

Herbivore::Herbivore(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestWeight, 
    int price, 
    string itemType
) : Animal(id, code, name, type, harvestWeight, price, itemType) {

}

void Herbivore::feed(Item i) {
    cout << "Herbivore eating..." << endl;
}

// ========================================================
// ===================== Carnivore ========================
// ========================================================

Carnivore::Carnivore(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestWeight, 
    int price, 
    string itemType
) : Animal(id, code, name, type, harvestWeight, price, itemType) {

}

void Carnivore::feed(Item i) {
    cout << "Carnivore eating..." << endl;
}

// ========================================================
// ===================== Omnivore =========================
// ========================================================
Omnivore::Omnivore(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestWeight, 
    int price, 
    string itemType
) : Animal(id, code, name, type, harvestWeight, price, itemType) {

}

void Omnivore::feed(Item i) {
    cout << "Omnivore eating..." << endl;
}