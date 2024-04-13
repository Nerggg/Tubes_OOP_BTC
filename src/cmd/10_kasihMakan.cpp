#include "../lib/Player.hpp"

// ========================================================
// ===================== KASIH_MAKAN ======================
// ========================================================

void Peternak::kasihMakan()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    sc << BOLD CYAN << "Pilih petak kandang yang akan diberi makan" << RESET << endl;
    cetakPeternakan();
    string choice;
    Animal *animal = nullptr;
    Item *item = nullptr;
    Product *produk = nullptr;
    try
    {
        while (true)
        {

            sc << BOLD GREEN << "Petak kandang: ";
            cin >> choice;
            animal = barn.getItem(choice);
            Animal *hewan = barn.getItem(choice);
            sc << BOLD CYAN << "Kamu memilih " << BOLD YELLOW << hewan->getName() << BOLD CYAN << " untuk diberi makan." << RESET << endl;
            break;
        }
    }
    catch (const std::out_of_range &e)
    {
        sc << BOLD RED << "Kamu memilih kandang kosong." << endl;
        sc << "Silahkan masukkan kandang yang berisi ternak." << endl;
    }
    try
    {
        sc << BOLD CYAN << "Pilih pangan yang akan diberikan:" << RESET << endl;
        cetakPenyimpanan();
        while (true)
        {
            sc << BOLD GREEN << "\nSlot: " << RESET;
            cin >> choice;
            item = inventory.getItem(choice);
            produk = (Product *)item;
            if (item->isBuilding())
            {
                sc << BOLD RED << "Apa yang kamu lakukan?\?!! Kamu mencoba untuk memberi makan itu?!!" << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << endl;
            }
            else if (!produk->isEdibleAnimal() && !produk->isEdiblePlant())
            {
                sc << BOLD RED << "Itu produk yang tidak bisa dimakan sobat." << endl;
                sc << "Silahkan masukkan slot yang berisi makanan." << endl;
            }
            else
            {
                animal->feed(produk);
                inventory.DeleteItemAt(choice);
                sc << "\n"
                   BOLD GREEN << animal->getName() << BOLD CYAN << " sudah diberi makan dan beratnya menjadi " << BOLD YELLOW << animal->getWeight() << RESET << endl;
                break;
            }
        }
    }
    catch (const std::out_of_range &e)
    {
        sc << BOLD RED << "Kamu memilih petak kosong." << endl;
        sc << "Silahkan masukkan kandang yang berisi ternak." << endl;
    }
    catch (wrongFoodException e)
    {
        sc << e.what() << '\n';
    }
}

// catch (out_of_range &e)
// {
//     sc << BOLD RED << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
//     sc << "Silahkan masukkan slot yang berisi makanan." << endl;
// }
