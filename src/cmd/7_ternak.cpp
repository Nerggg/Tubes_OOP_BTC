#include "../lib/Player.hpp"

// ========================================================
// ======================= TERNAK =========================
// ========================================================

void Peternak::ternak() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
     map<string, Item *> tempInv = inventory.getAllItems();
    map<string, Animal *> siapTernak;

    for (const auto &pair : tempInv)
    {
        if (pair.second->isAnimal())
        {
            siapTernak.insert({pair.first, dynamic_cast<Animal *>(pair.second)});
        }
    }

    if (siapTernak.empty())
    {
        sc << BOLD RED << "Anda tidak punya hewan" << RESET << endl
           << endl;
        return;
    }

    if (barn.getEmptySlotsCount() == 0)
    {
        sc << BOLD RED << "Peternakan anda penuh" << RESET << endl
           << endl;
        return;
    }

    sc << BOLD GREEN << "Pilih hewan dari penyimpanan" << RESET << endl;
    cetakPenyimpanan();
    bool cek = false;
    string slot;
    while (!cek)
    {
        sc << GREEN << "Slot: " << RESET;
        cin >> slot;
        for (const auto &pair : siapTernak)
        {
            if (pair.first == slot)
            {
                cek = true;
                sc << BOLD GREEN << "Kamu memilih " << pair.second->getName() << RESET << endl;
            }
        }
        if (!cek)
        {
            sc << BOLD RED << "Slot tidak sesuai, silahkan masukkan kembali" << RESET << endl;
        }
    }

    sc << BOLD GREEN << "Pilih petak yang ingin ditanami" << RESET << endl;
    cetakPeternakan();
    cek = false;
    while (!cek)
    {
        string petak;
        sc << GREEN << "Petak tanah: " << RESET;
        cin >> petak;
        if (barn.cekSlot(petak))
        {
            barn.InsertItemAt(siapTernak[slot], petak);
            inventory.DeleteItemAt(slot);
            cek = true;
            sc << GREEN << "Dengan hati-hati, kamu meletakkan seekor " << siapTernak[slot]->getName() << " di kandang" << RESET << endl;
            sc << GREEN << siapTernak[slot]->getName() << " telah menjadi peliharaanmu sekarang!" << RESET << endl;
        }
        if (!cek)
        {
            sc << BOLD RED << "Petak tidak sesuai, silahkan masukkan kembali" << RESET << endl;
        }
    }
}

