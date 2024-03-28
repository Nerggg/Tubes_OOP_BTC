#include "headers/Item.hpp"

// Static Attribute
map<string, Product*> Product::ProductData;
map<string, Building*> Building::BuildingData;

// ========================================================
// ======================= Item ===========================
// ========================================================

Item::Item() {
    this->id = 0;
    this->code = "";
    this->name = "";
    this->type = "";
    this->price = 0;
    this->itemType = "";
}

Item::Item(
    int id, 
    string code, 
    string name, 
    string type, 
    int price, 
    string itemType
) {
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
    this->price = price;
    this->itemType = itemType;
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
    int price, 
    string itemType
) : Item(id, code, name, type, price, itemType) {
    this->origin = origin;
    this->addedWeight = addedWeight;
}

ostream& operator<<(ostream& out, Product x) {
    out << "ID: "           << x.id    << endl;
    out << "Product Code: "  << x.code  << endl;
    out << "Product Name: "  << x.name  << endl;
    out << "Product Type: "  << x.type  << endl;
    out << "Product Origin: "   << x.origin  << endl;
    out << "Product Added Weight: "   << x.addedWeight  << endl;
    out << "Product Price: " << x.price << endl;
    out << endl;

    return out;
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
    map<string, int> recipe, 
    string itemType
) : Item(id, code, name, type, price, itemType) {
    this->recipe = recipe;
}

ostream& operator<<(ostream& out, Building x) {
    out << "ID: "           << x.id    << endl;
    out << "Product Code: "  << x.code  << endl;
    out << "Product Name: "  << x.name  << endl;
    out << "Product Price: " << x.price << endl << endl;

    out << "[Product Ingredients]" << endl;
    for (const auto& pair : x.recipe) {
        cout << "- " << pair.first << ": " << pair.second << endl;
    }
    out << endl;

    return out;
}