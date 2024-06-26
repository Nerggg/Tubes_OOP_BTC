#include "../lib/Player.hpp"

// ========================================================
// ======================= MAKAN ==========================
// ========================================================

void Player::makan()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    int totalFood = 0;
    sc << BOLD CYAN << "Pilih makanan dari penyimpanan" << RESET << endl;
    cetakPenyimpanan();
    for (const auto &pair : inventory.getAllItems())
    {
        if (pair.second->isProduct())
        {
            totalFood++;
        }
    }
    if (inventory.getAllItems().empty())
    {
        sc << BOLD RED << "Inventory kosong!" << endl;
    }
    else if (totalFood == 0)
    {
        sc << BOLD RED << "Tidak terdapat makanan pada inventory!" << endl;
    }
    else
    {
        string choice;
        while (true)
        {
            Item *item = nullptr;
            try
            {
                sc << "\nSlot: ";
                cin >> choice;
                item = inventory.getItem(choice);
                if (item->isBuilding())
                {
                    sc << BOLD RED << "\nApa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << RESET << endl;
                    sc << "Silahkan masukkan slot yang berisi makanan." << RESET << endl;
                }
                else
                {
                    Product *produk = (Product *)item;
                    if (!produk->isEdibleAnimal() && !produk->isEdiblePlant())
                    {
                        sc << BOLD RED << "\nApa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << RESET << endl;
                        sc << "Silahkan masukkan slot yang berisi makanan." << RESET << endl;
                    }
                    else
                    {
                        sc << BOLD GREEN << "INI adalah tambahan " << BOLD YELLOW << produk->getAddedWeight() << RESET << endl;
                        this->weight = this->weight + produk->getAddedWeight();
                        inventory.DeleteItemAt(choice);
                        sc << BOLD GREEN << "\nDengan lahapnya, kamu memakan hidangan itu" << endl;
                        sc << BOLD GREEN << "Alhasil, berat badan kamu naik menjadi " << BOLD YELLOW << this->weight << RESET << endl;
                        break;
                    }
                }
            }
            catch (const std::out_of_range &e)
            {
                sc << BOLD RED << "\nKamu mengambil harapan kosong dari penyimpanan." << RESET << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << RESET << endl;
            }
        }
    }
}
