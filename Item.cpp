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

Product::Product(const Product& x) {
    this->id = x.id;
    this->code = x.code;
    this->name = x.name;
    this->type = x.type;
    this->origin = x.origin;
    this->addedWeight = x.addedWeight;
    this->price = x.price;
    this->itemType = x.itemType;
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
    map<string, int> recipe, 
    string itemType
) : Item(id, code, name, type, price, itemType) {
    this->recipe = recipe;
}

Building::Building(const Building& x) {
    this->id = x.id;
    this->code = x.code;
    this->name = x.name;
    this->type = x.type;
    this->price = x.price;
    this->recipe = x.recipe;
    this->itemType = x.itemType;
}

// ostream& operator<<(ostream& out, Building x) {
//     out << "ID: "           << x.id    << endl;
//     out << "Product Code: "  << x.code  << endl;
//     out << "Product Name: "  << x.name  << endl;
//     out << "Product Price: " << x.price << endl << endl;

//     out << "[Product Ingredients]" << endl;
//     for (const auto& pair : x.recipe) {
//         cout << "- " << pair.first << ": " << pair.second << endl;
//     }
//     out << endl;

//     return out;
// }

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

Item* Building::clone() {
    return new Building(*this);
}