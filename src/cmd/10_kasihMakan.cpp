#include "../lib/Player.hpp"

// ========================================================
// ===================== KASIH_MAKAN ======================
// ========================================================

void Peternak::kasihMakan()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());

    sc << "Pilih petak kandang yang akan diberi makan" << endl;
    cetakPeternakan();
    string choice;
    Animal *animal = nullptr;
    Item *item = nullptr;
    Product *produk = (Product *)item;

    while (true)
    {
        sc << "Petak kandang: ";
        cin >> choice;
        try
        {
            animal = barn.getItem(choice);
        }
        catch (out_of_range &e)
        {
            sc << BOLD RED << "Kamu memilih kandang kosong." << endl;
            sc << "Silahkan masukkan kandang yang berisi ternak." << endl;
        }
    }
    Animal *hewan = barn.getItem(choice);
    sc << "Kamu memilih " << hewan->getName() << " untuk diberi makan." << endl;
    sc << "Pilih pangan yang akan diberikan:" << endl;
    cetakPenyimpanan();
    while (true)
    {
        sc << "Slot: ";
        cin >> choice;
        try
        {
            item = inventory.getItem(choice);
        }
        catch (out_of_range& e)
        {
            sc << BOLD RED << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            sc << "Silahkan masukkan slot yang berisi makanan." << endl;
        }
        if (item->isBuilding())
        {
            sc << BOLD RED << "Apa yang kamu lakukan?\?!! Kamu mencoba untuk memberi makan itu?!!" << endl;
            sc << "Silahkan masukkan slot yang berisi makanan." << endl;
        }
        if (!produk->isEdibleAnimal() && !produk->isEdiblePlant())
        {
            sc << BOLD RED << "Itu produk yang tidak bisa dimakan sobat." << endl;
            sc << "Silahkan masukkan slot yang berisi makanan." << endl;
        }
        else
        {
            map<string, Animal *> ladang = barn.getAllItems();
            for (const auto &pair : ladang)
            {
                if (pair.first == choice)
                {
                    sc << BOLD GREEN << "Kamu memilih " << pair.second->getName() << RESET << endl;
                }
            }
        }
    }
    animal->feed(produk);
    sc << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    sc << BOLD GREEN << "Alhasil, berat badan kamu naik menjadi " << this->weight << endl;
}