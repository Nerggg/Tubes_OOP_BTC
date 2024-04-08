#include "../lib/Player.hpp"

// ========================================================
// ======================= MAKAN ==========================
// ========================================================

void Player::makan()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    int totalFood = 0;
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
        cetakPenyimpanan();
        string choice;
        while (true)
        {
            sc << "Slot: ";
            cin >> choice;
            Item *item = nullptr;
            try
            {
                item = inventory.getItem(choice);
            }
            catch (out_of_range &e)
            {
                sc << BOLD RED << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << endl;
            }
            if (item->isBuilding())
            {
                sc << BOLD RED << "Apa yang kamu lakukan?\?!! Kamu mencoba untuk memakan itu?!!" << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << endl;
            }
            Product *produk = (Product *)item;
            if (!produk->isEdibleAnimal() && !produk->isEdiblePlant())
            {
                sc << BOLD RED << "Apa yang kamu lakukan?\?!! Kamu mencoba untuk memakan itu?!!" << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << endl;
            }
            else
            {
                inventory.DeleteItemAt(choice);
                sc << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
                sc << BOLD GREEN << "Alhasil, berat badan kamu naik menjadi " << this->weight << endl;
            }
        }
    }
}
