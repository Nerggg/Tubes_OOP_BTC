#include "headers/Item.hpp"

// Static Attribute
// map<string, Product*> Product::ProductData;
// map<string, Building*> Building::BuildingData;
map<string, Item*> Item::ItemData;

// ========================================================
// ======================= Item ===========================
// ========================================================

Item::Item() {
    this->id = 0;
    this->code = "";
    this->name = "";
    this->type = "";
    this->price = 0;
}

Item::Item(
    int id, 
    string code, 
    string name, 
    string type, 
    int price
) {
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
    this->price = price;
}

string Item::getName() {
    return this->name;
}

ostream& Item::printDetails(ostream& out) {
    out << "ID: "           << this->id    << endl;
    out << "Product Code: "  << this->code  << endl;
    out << "Product Name: "  << this->name  << endl;
    out << "Product Type: "  << this->type  << endl;
    out << "Product Price: " << this->price << endl;
    out << endl;

    return out;
}

ostream& operator<<(ostream& out, Item* x) {
    return x->printDetails(out);
}

SlowPrinter Item::slowPrintDetails(SlowPrinter slowp) {
    slowp << "ID: "           << this->id    << endl;
    slowp << "Product Code: "  << this->code  << endl;
    slowp << "Product Name: "  << this->name  << endl;
    slowp << "Product Type: "  << this->type  << endl;
    slowp << "Product Price: " << this->price << endl;
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Item* I) {
    return I->slowPrintDetails(slowp);
}

// ========================================================
// ====================== Product =========================
// ========================================================

Product::Product() : Item() {
    this->origin = "";
    this->addedWeight = 0;
}

Product::Product(
    int id, 
    string code, 
    string name, 
    string type,
    string origin, 
    int addedWeight, 
    int price
) : Item(id, code, name, type, price) {
    this->origin = origin;
    this->addedWeight = addedWeight;
}

Product::Product(const Product& x) {
    this->id = x.id;
    this->code = x.code;
    this->name = x.name;
    this->type = x.type;
    this->origin = x.origin;
    this->addedWeight = x.addedWeight;
    this->price = x.price;
}

ostream& Product::printDetails(ostream& out) {
    out << "ID: "            << this->id    << endl;
    out << "Product Code: "  << this->code  << endl;
    out << "Product Name: "  << this->name  << endl;
    out << "Product Type: "  << this->type  << endl;
    out << "Product Origin: " << this->origin << endl;
    out << "Product Added Weight: " << this->addedWeight << endl;
    out << "Product Price: " << this->price << endl;
    out << endl;

    return out;
}

ostream& operator<<(ostream& out, Product* x) {
    return x->printDetails(out);
}

SlowPrinter Product::slowPrintDetails(SlowPrinter slowp) {
    slowp << "ID: "            << this->id    << endl;
    slowp << "Product Code: "  << this->code  << endl;
    slowp << "Product Name: "  << this->name  << endl;
    slowp << "Product Type: "  << this->type  << endl;
    slowp << "Product Origin: " << this->origin << endl;
    slowp << "Product Added Weight: " << this->addedWeight << endl;
    slowp << "Product Price: " << this->price << endl;
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Product* x) {
    return x->slowPrintDetails(slowp);
}

Item* Product::clone() {
    return new Product(*this);
}
// ========================================================
// ===================== Building =========================
// ========================================================

Building::Building() : Item() {
}

Building::Building(
    int id, 
    string code, 
    string name, 
    string type, 
    int price,
    map<string, int> recipe
) : Item(id, code, name, type, price) {
    this->recipe = recipe;
}

Building::Building(const Building& x) {
    this->id = x.id;
    this->code = x.code;
    this->name = x.name;
    this->type = x.type;
    this->price = x.price;
    this->recipe = x.recipe;
}

ostream& Building::printDetails(ostream& out) {
    out << "ID: "           << this->id    << endl;
    out << "Building Code: "  << this->code  << endl;
    out << "Building Name: "  << this->name  << endl;
    out << "Building Type: "  << this->type  << endl;
    out << "Building Price: " << this->price << endl << endl;

    out << "[Building Ingredients]" << endl;
    for (const auto& pair : this->recipe) {
        cout << "- " << pair.first << ": " << pair.second << endl;
    }
    out << endl;

    return out;
}

ostream& operator<<(ostream& out, Building* x) {
    return x->printDetails(out);
}

SlowPrinter Building::slowPrintDetails(SlowPrinter slowp) {
    slowp << "ID: "           << this->id    << endl;
    slowp << "Building Code: "  << this->code  << endl;
    slowp << "Building Name: "  << this->name  << endl;
    slowp << "Building Type: "  << this->type  << endl;
    slowp << "Building Price: " << this->price << endl << endl;

    slowp << "[Building Ingredients]" << endl;
    for (const auto& pair : this->recipe) {
        slowp << "- " << pair.first << ": " << pair.second << endl;
    }
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Building* x) {
    return x->slowPrintDetails(slowp);
}

Item* Building::clone() {
    return new Building(*this);
}