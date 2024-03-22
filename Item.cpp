#include "headers/Item.hpp"

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