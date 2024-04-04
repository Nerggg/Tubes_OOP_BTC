#include "./lib/Inventory.hpp"

int main(){
    Inventory<Item> inv(10, 10);
    inv.printInventory();
}