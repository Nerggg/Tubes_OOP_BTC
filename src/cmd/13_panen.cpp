#include "../lib/Player.hpp"

// ========================================================
// ======================= PANEN ==========================
// ========================================================

void Petani::panen()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    // Run command
    cetakLadang();

    if (farm.getAllItems().empty())
    {
        sc << BOLD RED << "Anda tidak punya tanaman" << RESET << endl
           << endl;
        return;
    }
    map<string, Plant *> tempFarm = farm.getAllItems();
    map<string, Plant *> siapPanen;
    map<string, int> countPlant;

    for (const auto &pair : tempFarm)
    {
        if (pair.second->getHarvestAge() <= pair.second->getAge())
        {
            countPlant[pair.second->getName()]++;
            siapPanen.insert(pair);
        }
    }

    if (siapPanen.empty())
    {
        sc << BOLD RED << "Anda tidak punya tanaman untuk dipanen" << RESET << endl
           << endl;
        return;
    }
    sc << BOLD GREEN << "Pilih tanaman siap panen yang kamu miliki" << RESET << endl;
    int count = 1;
    for (const auto &pair : countPlant)
    {
        if (pair.second >= 0)
        {
            sc << BLUE << count << ". " << pair.first << " (" << pair.second << " petak siap panen)" << RESET << endl;
            count++;
        }
    }

    int numberPlant;
    int size = countPlant.size();
    sc << BOLD GREEN << "Nomor tanaman yang ingin dipanen: " << RESET;
    cin >> numberPlant;
    while (numberPlant < 1 || numberPlant > size)
    {
        sc << BOLD RED << "Maaf masukkan anda salah, silahkan masukkan kembali : " << RESET;
        cin >> numberPlant;
    }

    int quantity;
    sc << BOLD GREEN << "Berapa petak yang ingin dipanen: " << RESET;
    cin >> quantity;
    auto it = countPlant.begin();
    advance(it, numberPlant - 1);
    while (quantity < 1 || quantity > it->second)
    {
        sc << BOLD RED << "Maaf jumlah tidak sesuai, silahkan masukkan kembali : " << RESET;
        cin >> quantity;
    }

    if (inventory.getEmptySlotsCount() < quantity)
    {
        sc << BOLD RED << "Jumlah penyimpanan tidak cukup!" << RESET << endl;
        sc << BOLD RED << "Panen Gagal Dilakukan" << RESET << endl;
        return;
    }
    sc << BOLD GREEN << "Pilih petak yang ingin dipanen:" << RESET << endl;
    for (int i = 1; i <= quantity; i++)
    {
        bool cek = false;
        while (!cek)
        {
            string petak;
            sc << GREEN << "Petak Ke-" << i << ": " << RESET;
            cin >> petak;
            for (auto it2 = siapPanen.begin(); it2 != siapPanen.end();)
            {
                if (it2->first == petak && it2->second->getName() == it->first)
                {
                    cek = true;
                    map<string, Item *> itemData = Item::getItemData();
                    for (const auto &pair : itemData)
                    {
                        if (pair.second->isProduct())
                        {
                            Item *temp = pair.second->clone();
                            Product *product = (Product*) temp;
                            if (product->getOrigin() == it->first)
                            {
                                inventory.insertItem(product);
                            }
                        }
                    }
                    farm.DeleteItemAt(petak);
                    it2 = siapPanen.erase(it2);
                }
                else
                {
                    ++it2;
                }
            }
            if (!cek)
            {
                sc << BOLD RED << "Petak tidak sesuai, silahkan masukkan kembali" << RESET << endl;
            }
        }
    }
}

void Peternak::panen()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());
    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl
       << endl;
    cetakLadang();

    if (barn.getAllItems().empty())
    {
        sc << BOLD RED << "Anda tidak punya hewan" << RESET << endl
           << endl;
        return;
    }

    map<string, Animal *> tempBarn = barn.getAllItems();
    map<string, Animal *> siapPanen;
    map<string, int> countAnimal;

    for (const auto &pair : tempBarn)
    {
        if (pair.second->getHarvestWeight() <= pair.second->getWeight())
        {
            countAnimal[pair.second->getName()]++;
            siapPanen.insert(pair);
        }
    }

    if (siapPanen.empty())
    {
        sc << BOLD RED << "Anda tidak punya hewan untuk dipanen" << RESET << endl
           << endl;
        return;
    }

    sc << BOLD GREEN << "Pilih hewan siap panen yang kamu miliki" << RESET << endl;
    int count = 1;
    for (const auto &pair : countAnimal)
    {
        if (pair.second >= 0)
        {
            sc << BLUE << count << ". " << pair.first << " (" << pair.second << " petak siap panen)" << RESET << endl;
            count++;
        }
    }

    int numberAnimal;
    int size = countAnimal.size();
    sc << BOLD GREEN << "Nomor hewan yang ingin dipanen: " << RESET;
    cin >> numberAnimal;
    while (numberAnimal < 1 || numberAnimal > size)
    {
        sc << BOLD RED << "Maaf masukkan anda salah, silahkan masukkan kembali : " << RESET;
        cin >> numberAnimal;
    }

    int quantity;
    sc << BOLD GREEN << "Berapa petak yang ingin dipanen: " << RESET;
    cin >> quantity;
    auto it = countAnimal.begin();
    advance(it, numberAnimal - 1);
    while (quantity < 1 || quantity > it->second)
    {
        sc << BOLD RED << "Maaf jumlah tidak sesuai, silahkan masukkan kembali : " << RESET;
        cin >> quantity;
    }

    if (inventory.getEmptySlotsCount() < quantity)
    {
        sc << BOLD RED << "Jumlah penyimpanan tidak cukup!" << RESET << endl;
        sc << BOLD RED << "Panen Gagal Dilakukan" << RESET << endl;
        return;
    }
    sc << BOLD GREEN << "Pilih petak yang ingin dipanen:" << RESET << endl;
    for (int i = 1; i <= quantity; i++)
    {
        bool cek = false;
        while (!cek)
        {
            string petak;
            sc << GREEN << "Petak Ke-" << i << ": " << RESET;
            cin >> petak;
            for (auto it2 = siapPanen.begin(); it2 != siapPanen.end();)
            {
                if (it2->first == petak && it2->second->getName() == it->first)
                {
                    cek = true;
                    map<string, Item *> itemData = Item::getItemData();
                    for (const auto &pair : itemData)
                    {
                        if (pair.second->isProduct())
                        {
                            Item *temp = pair.second->clone();
                            Product *product = (Product*) temp;
                            if (product->getOrigin() == it->first)
                            {
                                inventory.insertItem(product);
                            }
                        }
                    }
                    barn.DeleteItemAt(petak);
                    it2 = siapPanen.erase(it2);
                }
                else
                {
                    ++it2;
                }
            }
            if (!cek)
            {
                sc << BOLD RED << "Petak tidak sesuai, silahkan masukkan kembali" << RESET << endl;
            }
        }
    }
}