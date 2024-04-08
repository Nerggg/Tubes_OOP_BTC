#include "../lib/Player.hpp"
#include "../lib/Store.hpp"
#include "../lib/Item.hpp"
#include "../lib/Exception.hpp"
#include <sstream>

// ========================================================
// ======================== BELI ==========================
// ========================================================

void Walikota::beli() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "walikota" << RESET << endl << endl;
}

void Petani::beli() {
    // Initialize slowprinter
    // SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    vector<string> itemList;
    map<string, int>::iterator itStore;
    map<string, int> storeTemp = Store::getStoreData();
    Item *item;
    int num = 1;
    for (itStore = storeTemp.begin(); itStore != storeTemp.end(); itStore++) {
        if (itStore->second == 0) {
            continue;
        }
        item = Item::getItemData()[itStore->first];
        cout << num << ". " << itStore->first << " - " << item->getPrice() << " (" << itStore->second << ")" << endl;
        itemList.push_back(itStore->first);
        num++;
    }

    map<string, Item*>::iterator itItem;
    map<string, Item*> itemTemp = Item::getItemData();
    for (itItem = itemTemp.begin(); itItem != itemTemp.end(); itItem++) {
        cout << num << ". " << itItem->first << " - " << itItem->second->getPrice() << endl;
        itemList.push_back(itItem->first);
        num++;
    }

    cout << endl << "Uang Anda: " << this->money << endl;
    cout << "Slot penyimpanan tersedia: " << this->inventory.getEmptySlotsCount() << endl << endl;

    long unsigned int buy;
    int q;
    bool valid = false;

    while (!valid) {
        cout << "Barang yang ingin dibeli: ";
        cin >> buy;
        cout << "Kuantitas: ";
        cin >> q;

        try {
            if (buy <= 0 || buy >= itemList.size()-1) {
                throw vectorOutOfRangeException();
            }
            else if (this->money < Item::getItemData()[itemList.at(buy-1)]->getPrice() * q) {
                throw moneyNotEnoughException();
            }
            else if (this->inventory.getEmptySlotsCount() < q) {
                throw storageNotEnoughException();
            }
            valid = true;
        }
        catch (vectorOutOfRangeException e) {
            cout << e.what() << endl;
            cout << "Masukkan barang yang ingin dibeli diantara 1 sampai " << itemList.size() << endl;
        }
        catch (moneyNotEnoughException e) {
            cout << e.what() << endl;
        }
        catch (storageNotEnoughException e) {
            cout << e.what() << endl;
        }
    }

    this->money -= Item::getItemData()[itemList.at(buy-1)]->getPrice();
    cout << "Selamat Anda berhasil membeli " << q << " " << itemList.at(buy-1) << ". Uang Anda tersisa " << this->money << endl << endl;

    cout <<  "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;

    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

    valid = false;
    while (!valid) {
        cout << "Petak slot: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (slots.size() != q) {
            cout << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            bool occupied = false;
            for (int i = 0; i < slots.size(); i++) {
                if (this->inventory.getItem(slots.at(i)) != NULL) {
                    cout << "Slot " << slots.at(i) << " telah diambil" << endl;
                    occupied = true;
                    while (!slots.empty()) {
                        slots.pop_back();
                    }
                    break;
                }
            }
            if (occupied == false) {
                valid = true;
            }
        }
    }

    for (unsigned long int i = 0; i < slots.size(); i++) {
        this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
    }

    cout << Item::getItemData()[itemList.at(buy-1)]->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
}

void Peternak::beli() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "peternak" << RESET << endl << endl;
}