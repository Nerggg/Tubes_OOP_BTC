#include "headers/Plant.hpp"

// Static Attributes
// map<string, Plant*> Plant::PlantData;

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

Plant::Plant(const Plant& p) {
    this->id = p.id;
    this->code = p.code;
    this->name = p.name;
    this->type = p.type;
    this->harvestAge = p.harvestAge;
    this->age = p.age;
    this->price = p.price;
}

ostream& Plant::printDetails(ostream& out) {
    out << "ID: "          << this->id     << endl;
    out << "Plant Code: "  << this->code   << endl;
    out << "Plant Name: "  << this->name   << endl;
    out << "Plant Type: "  << this->type   << endl;
    out << "Plant Age: "   << this->age    << endl;
    out << "Plant Harvest Age: " << this->harvestAge << endl;
    out << "Plant Price: " << this->price  << endl;
    out << endl;

    return out;
}

ostream& operator<<(ostream& out, Plant* p) {
    return p->printDetails(out);
}

Item* Plant::clone() {
    return new Plant(*this);
}