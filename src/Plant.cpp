#include "lib/Plant.hpp"

// ========================================================
// ======================= Plant ==========================
// =================== Constructors =======================
// ========================================================

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
    int price
) : Item(id, code, name, type, price) {
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

Item* Plant::clone() {
    return new Plant(*this);
}

// ========================================================
// ======================= Plant ==========================
// ======================= Printers =======================
// ========================================================

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

SlowPrinter Plant::slowPrintDetails(SlowPrinter slowp) {
    slowp << "ID: "          << this->id     << endl;
    slowp << "Plant Code: "  << this->code   << endl;
    slowp << "Plant Name: "  << this->name   << endl;
    slowp << "Plant Type: "  << this->type   << endl;
    slowp << "Plant Age: "   << this->age    << endl;
    slowp << "Plant Harvest Age: " << this->harvestAge << endl;
    slowp << "Plant Price: " << this->price  << endl;
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Plant* p) {
    return p->slowPrintDetails(slowp);
}

// ========================================================
// ======================= Plant ==========================
// ======================= Getters ========================
// ========================================================

int Plant::getHarvestAge() {
    return this->harvestAge;
}

int Plant::getAge() {
    return this->age;
}

// ========================================================
// ======================= Plant ==========================
// ======================= Setters ========================
// ========================================================

void Plant::operator++(int) {
    this->age++;
}

// ========================================================
// ======================= Plant ==========================
// =================== Type Checkers ======================
// ========================================================

bool Plant::isAnimal() {
    return false;
}

bool Plant::isPlant() {
    return true;
}

bool Plant::isProduct() {
    return false;
}

bool Plant::isBuilding() {
    return false;
}