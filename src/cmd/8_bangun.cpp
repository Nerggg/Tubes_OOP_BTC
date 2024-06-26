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
    map<string, Item *> storage = inventory.getAllItems();
    string choice;
    Building *building = nullptr;
    bool safe = true;
    int price = 0;
    string formattedName;
    try
    {
        sc << BOLD CYAN << "Resep bangunan yang ada adalah sebagai berikut." << RESET << endl;
        int i = 1;
        for (const auto &pair : itemData)
        {
            if (pair.second->isBuilding())
            {
                Item *temp = pair.second->clone();
                Building *building = (Building *)temp;
                sc << BOLD YELLOW << i << ". " << pair.second->getName() << " (";
                map<string, int> recipe = building->getRecipe();
                for (const auto &recipePair : recipe)
                {
                    formattedName = recipePair.first;
                    std::replace(formattedName.begin(), formattedName.end(), '_', ' ');
                    sc << BOLD YELLOW << recipePair.first << " " << recipePair.second << ", ";
                }
                sc << BOLD YELLOW << ")" << endl;
                i++;
            }
        }
        while (true)
        {
            sc << BOLD GREEN << "\nBangunan yang ingin dibangun: " << RESET;
            cin >> choice;
            auto temp = itemData.find(choice);
            if (temp == itemData.end())
            {
                sc << BOLD RED << "Kamu tidak punya resep bangunan tersebut!" << RESET << endl;
                continue;
            }
            building = (Building *)temp->second;
            map<string, int> recipe = building->getRecipe();
            for (const auto &recipePair : recipe)
            {
                int availableItem = inventory.countItem(recipePair.first);
                if (availableItem < recipePair.second)
                {
                    safe = false;
                    break;
                }
            }
            if (!safe)
            {
                sc << BOLD RED << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan";
                sc.setMult(0);
                sc.setDelay(sc.getDelay() - 15);
                map<string, int> recipe = building->getRecipe();
                for (const auto &recipePair : recipe)
                {
                    int availableItem = inventory.countItem(recipePair.first);
                    if (availableItem < recipePair.second)
                    {
                        formattedName = recipePair.first;
                        std::replace(formattedName.begin(), formattedName.end(), '_', ' ');
                        sc << ", " << recipePair.second - availableItem << " " << formattedName;
                    }
                }
                sc << BOLD RED << "!" << endl;
                sc.resetMult();
                sc.resetDelay();
            }
            else
            {
                map<string, int>
                    recipe = building->getRecipe();
                for (const auto &recipePair : recipe)
                {
                    int total = recipePair.second;
                    for (auto &inventoryPair : storage)
                    {
                        if (total == 0)
                        {
                            break;
                        }
                        else if (inventoryPair.second->getName() == recipePair.first)
                        {
                            inventory.DeleteItemAt(inventoryPair.first);
                            total--;
                        }
                    }
                }
                for (const auto &pair : itemData)
                {
                    if (pair.second->isBuilding() && pair.second->getName() == building->getName())
                    {
                        Item *temp = pair.second->clone();
                        Building *newBuilding = (Building *)temp;
                        inventory.insertItem(newBuilding);
                        break;
                    }
                }
                formattedName = building->getName();
                std::replace(formattedName.begin(), formattedName.end(), '_', ' ');
                sc << BOLD YELLOW << formattedName << BOLD GREEN << " berhasil dibangun dan telah menjadi milik walikota!" << RESET << endl;
                break;
            }
        }
    }
    catch (const std::out_of_range &e)
    {
        sc << e.what() << endl;
    }
}