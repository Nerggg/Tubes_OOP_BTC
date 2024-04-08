#include "../lib/Player.hpp"
#include <algorithm>
#include <string>

// ========================================================
// ======================= BANGUN =========================
// ========================================================

void Walikota::bangun()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    map<string, Item *> itemData = Item::getItemData();
    sc << BOLD GREEN << "Resep bangunan yang ada adalah sebagai berikut." << RESET << endl;

    for (const auto &pair : itemData)
    {
        int i = 0;
        if (pair.second->isBuilding())
        {
            Item *temp = pair.second->clone();
            Building *building = (Building *)temp;
            sc << BOLD YELLOW << "1.\t" << pair.second->getName() << " (" << pair.second->getPrice() << " gulden, ";
            map<string, int> recipe = building->getRecipe();
            for (const auto &recipePair : recipe)
            {
                sc << BOLD YELLOW << recipePair.first << " " << recipePair.second << ", ";
            }
            sc << BOLD YELLOW << ")" << endl;
        }
        i++;
    }

    string choice;
    Building *building = nullptr;
    while (true)
    {
        sc << BOLD GREEN << "\nBangunan yang ingin dibangun: " << endl;
        cin >> choice;
        auto temp = itemData.find(choice);
        if (temp == itemData.end())
        {
            sc << BOLD RED << "Kamu tidak punya resep bangunan tersebut!" << endl;
            continue;
        }
        building = (Building *)temp->second;

        int price = building->getPrice();

        if (this->money < price)
        {
            sc << BOLD RED << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << price - this->money << " gulden, ";
        }
        map<string, int> recipe = building->getRecipe();
        map<string, Animal *> siapTernak;
        for (const auto &recipePair : recipe)
        {
            for (const auto &inventoryPair : inventory.getAllItems())
            {
                if (inventoryPair.second->getName() == recipePair.first)
                {
                    int availableItem = inventory.countItem(inventoryPair.second->getName());
                    if (availableItem < recipePair.second)
                    {
                        sc << recipePair.second - availableItem << " " << recipePair.first << ", ";
                    }
                    break;
                }
            }
        }
        sc << BOLD RED << "!" << endl;
    }

    string formattedName = building->getName();

    std::replace(formattedName.begin(), formattedName.end(), '_', ' ');
    sc << BOLD GREEN << formattedName << " berhasil dibangun dan telah menjadi milik walikota!" << endl;
}
