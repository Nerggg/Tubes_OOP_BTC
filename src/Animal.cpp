#include "headers/Animal.hpp"

// Static Attribute
map<string, Animal*> Animal::AnimalData;

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
    int price
) : Item(id, code, name, type, price) {
    this->harvestWeight = harvestWeight;
    this->weight = 0;
}

Animal::Animal(const Animal& a) {
    this->id = a.id;
    this->code = a.code;
    this->name = a.name;
    this->type = a.type;
    this->harvestWeight = a.harvestWeight;
    this->weight = a.weight;
    this->price = a.price;
}

ostream& Animal::printDetails(ostream& out) {
    out << "ID: "           << this->id    << endl;
    out << "Animal Code: "  << this->code  << endl;
    out << "Animal Name: "  << this->name  << endl;
    out << "Animal Type: "  << this->type  << endl;
    out << "Animal Weight: "   << this->weight  << endl;
    out << "Animal Harvest Weight: " << this->harvestWeight << endl;
    out << "Animal Price: " << this->price << endl;
    out << endl;

    return out;
}

ostream& operator<<(ostream& out, Animal* x) {
    return x->printDetails(out);
}

SlowPrinter Animal::slowPrintDetails(SlowPrinter slowp) {
    slowp << "ID: "           << this->id    << endl;
    slowp << "Animal Code: "  << this->code  << endl;
    slowp << "Animal Name: "  << this->name  << endl;
    slowp << "Animal Type: "  << this->type  << endl;
    slowp << "Animal Weight: "   << this->weight  << endl;
    slowp << "Animal Harvest Weight: " << this->harvestWeight << endl;
    slowp << "Animal Price: " << this->price << endl;
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Animal* x) {
    return x->slowPrintDetails(slowp);
}

// void Animal::feed(Item t) {
//     cout << "Animal eating..." << endl;
// }

// ========================================================
// ===================== Herbivore ========================
// ========================================================

Herbivore::Herbivore(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestWeight, 
    int price
) : Animal(id, code, name, type, harvestWeight, price) {

}

Herbivore::Herbivore(const Herbivore& h) : Animal(h) {

}

Item* Herbivore::clone() {
    return new Herbivore(*this);
}

void Herbivore::feed(Item* i) {
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
    int price
) : Animal(id, code, name, type, harvestWeight, price) {

}

Carnivore::Carnivore(const Carnivore& c) : Animal(c) {

}

Item* Carnivore::clone() {
    return new Carnivore(*this);
}

void Carnivore::feed(Item* i) {
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
    int price
) : Animal(id, code, name, type, harvestWeight, price) {

}

Omnivore::Omnivore(const Omnivore& o) : Animal(o) {

}

Item* Omnivore::clone() {
    return new Omnivore(*this);
}

void Omnivore::feed(Item* i) {
    cout << "Omnivore eating..." << endl;
}