#include "lib/Inventory.hpp"

int main() {
    Inventory::InventoryRows = 10;
    Inventory::InventoryCols = 10;

    Farm::FarmRows = 5;
    Farm::FarmCols = 7;

    Barn::BarnRows = 8;
    Barn::BarnCols = 9;

    Inventory i;
    Farm f;
    Barn b;

    // string slot = "C03";
    // i.data[i.getRow(slot)][i.getCol(slot)] = true;
    // f.data[i.getRow(slot)][i.getCol(slot)] = true;
    // b.data[i.getRow(slot)][i.getCol(slot)] = true;

    Plant* p = new Plant(1, "LMAO", "LOL", "XD", 10, 10, "Plant");
    i.insertItem(p);

    Animal* a = new Animal(69, "animal", "animal", "animalxd", 0, 0, "Animal");
    b.insertItem(a);

    Item* it = i.getItem("A01");
    cout << it;
    
    Item* it2 = b.getItem("A01");
    cout << it2;

    // cout << i;
    // cout << f;
    // cout << b;
    return 0;
}