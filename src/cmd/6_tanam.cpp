#include "../lib/Player.hpp"

// ========================================================
// ======================= TANAM ==========================
// ========================================================

void Petani::tanam()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    // Run command
    map<string, Item *> tempInv = inventory.getAllItems();
    map<string, Plant *> siapTanam;

    for (const auto &pair : tempInv)
    {
        if (pair.second->isPlant())
        {
            siapTanam.insert({pair.first, dynamic_cast<Plant *>(pair.second)});
        }
    }

    if (siapTanam.empty())
    {
        sc << BOLD RED << "Anda tidak punya tanaman" << RESET << endl
           << endl;
        return;
    }

    if (farm.getEmptySlotsCount() == 0)
    {
        sc << BOLD RED << "Ladang anda penuh" << RESET << endl
           << endl;
        return;
    }

    sc << BOLD GREEN << "Pilih tanaman dari penyimpanan" << RESET << endl;
    cetakPenyimpanan();
    bool cek = false;
    string slot;
    while (!cek)
    {
        sc << GREEN << "Slot: " << RESET;
        cin >> slot;
        for (const auto &pair : siapTanam)
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
    cetakLadang();
    cek = false;
    while (!cek)
    {
        string petak;
        sc << GREEN << "Petak tanah: " << RESET;
        cin >> petak;
        if (farm.cekSlot(petak))
        {
            farm.InsertItemAt(siapTanam[slot], petak);
            inventory.DeleteItemAt(slot);
            cek = true;
            sc << GREEN << "Cangkul, cangkul, cangkul yang dalam~!" << RESET << endl;
            sc << GREEN << siapTanam[slot]->getName() << " berhasil ditanam!" << RESET << endl;
        }
        if (!cek)
        {
            sc << BOLD RED << "Petak tidak sesuai, silahkan masukkan kembali" << RESET << endl;
        }
    }
}
