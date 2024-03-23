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