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
    Product *produk = nullptr;
    try
    {
        while (true)
        {

            sc << "Petak kandang: ";
            cin >> choice;
            animal = barn.getItem(choice);
            Animal *hewan = barn.getItem(choice);
            sc << "Kamu memilih " << hewan->getName() << " untuk diberi makan." << endl;
            break;
        }
    }
    catch (out_of_range &e)
    {
        sc << BOLD RED << "Kamu memilih kandang kosong." << endl;
        sc << "Silahkan masukkan kandang yang berisi ternak." << endl;
    }
    try
    {
        sc << "Pilih pangan yang akan diberikan:" << endl;
        cetakPenyimpanan();
        while (true)
        {
            sc << "\nSlot: ";
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
                   << animal->getName() << " sudah diberi makan dan beratnya menjadi " << animal->getWeight() << endl;
                break;
            }
        }
    }
    catch (out_of_range &e)
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
