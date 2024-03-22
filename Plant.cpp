#include "headers/Plant.hpp"

// Static Attributes
vector<Plant*> Plant::PlantData;

Plant::Plant() : Item() {
    this->harvestAge = 0;
    this->age = 0;
}

Plant::Plant(
    int id, 
    string code, 
    string name, 
    string type, 
    int harvestAge, 
    int price, 
    string itemType
) : Item(id, code, name, type, price, itemType) {
    this->harvestAge = harvestAge;
    this->age = 0;
}

ostream& operator<<(ostream& out, Plant p) {
    out << "ID: "          << p.id     << endl;
    out << "Plant Code: "  << p.code   << endl;
    out << "Plant Name: "  << p.name   << endl;
    out << "Plant Type: "  << p.type   << endl;
    out << "Plant Age: "   << p.age    << endl;
    out << "Plant Harvest Age: " << p.harvestAge << endl;
    out << "Plant Price: " << p.price  << endl;
    out << endl;

    return out;
}