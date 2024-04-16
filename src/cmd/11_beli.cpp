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
    sc << BOLD MAGENTA << "Selamat datang di toko!!" << endl; sc.setMult(0);
    sc << BOLD GREEN << "Berikut merupakan benda yang dapat Anda Beli" << endl;
    vector<string> itemList;
    map<string, int>::iterator itStore;
    map<string, int> storeTemp = Store::getStoreData();
    Item *item;
    int num = 1;
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 15);
    for (itStore = storeTemp.begin(); itStore != storeTemp.end(); itStore++) {
        if (itStore->second == 0 || Item::getItemData()[itStore->first]->isBuilding()) {
            continue;
        }
        item = Item::getItemData()[itStore->first];
        sc << BOLD CYAN << num << ". " << BOLD YELLOW << itStore->first << " - " << BOLD GREEN << item->getPrice() << BOLD CYAN << " (" << itStore->second << ")" << endl;
        itemList.push_back(itStore->first);
        num++;
    }

    map<string, Item*>::iterator itItem;
    map<string, Item*> itemTemp = Item::getItemData();
    for (itItem = itemTemp.begin(); itItem != itemTemp.end(); itItem++) {
        sc << BOLD CYAN << num << ". " << BOLD YELLOW << itItem->first << " - " << BOLD GREEN << itItem->second->getPrice() << endl;
        itemList.push_back(itItem->first);
        num++;
    }
    sc.resetMult();
    sc.resetDelay();

    sc << endl << BOLD MAGENTA << "Uang Anda: " << BOLD YELLOW << this->money << endl;
    sc << BOLD MAGENTA << "Slot penyimpanan tersedia: " << BOLD YELLOW << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << BOLD GREEN << "Barang yang ingin dibeli: " << RESET;
        cin >> buy;
        sc << BOLD GREEN << "Kuantitas: " << RESET;
        cin >> q;

        try {
            if (buy <= 0 || buy >= int(itemList.size()-1)) {
                throw vectorOutOfRangeException();
            }
            else if (this->money < Item::getItemData()[itemList.at(buy-1)]->getPrice() * q) {
                throw moneyNotEnoughException();
            }
            else if (this->inventory.getEmptySlotsCount() < q) {
                throw storageNotEnoughException();
            }
            else if (storeTemp[itemList.at(buy-1)] < q) {
                throw storeStockNotEnoughException();
            }
            valid = true;
        }
        catch (vectorOutOfRangeException e) {
            sc << e.what() << endl;
            sc << BOLD RED << "Masukkan barang yang ingin dibeli diantara" << BOLD YELLOW << "1" << BOLD RED << " sampai " << BOLD YELLOW << itemList.size() << RESET << endl;
        }
        catch (moneyNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storageNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storeStockNotEnoughException e) {
            sc << e.what() << endl;
        }
    }

    this->money -= Item::getItemData()[itemList.at(buy-1)]->getPrice();
    sc << BOLD MAGENTA << "Selamat Anda berhasil membeli " << BOLD YELLOW << q << " " << BOLD YELLOW << itemList.at(buy-1) << "." << BOLD GREEN << " Uang Anda tersisa " << BOLD YELLOW << this->money << endl << endl;

    sc << BOLD YELLOW << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;

    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Petak slot: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << BOLD RED << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << RESET << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            try {
                bool occupied = false;
                for (int i = 0; i < int(slots.size()); i++) {
                    if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                        sc << BOLD RED << "Slot " << BOLD YELLOW << slots.at(i) << BOLD RED << " telah diambil" << RESET << endl;
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
            catch (invalidSlotException e) {
                sc << e.what() << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
            catch (invalid_argument &e) {
                sc << BOLD RED << "Slot yang Anda masukkan tidak valid!" << RESET << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
        }
    }

    for (int i = 0; i < int(slots.size()); i++) {
        this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
    }

    if (Store::getStoreData().count(itemList.at(buy-1)) > 0) {
        Store::reduceStoreData(itemList.at(buy-1), q);
    }
    sc << BOLD YELLOW << Item::getItemData()[itemList.at(buy-1)]->getName() << BOLD GREEN << " berhasil disimpan dalam penyimpanan!" << RESET << endl;
}

void Petani::beli() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD MAGENTA << "Selamat datang di toko!!" << endl; sc.setMult(0);
    sc << BOLD GREEN << "Berikut merupakan benda yang dapat Anda Beli" << endl;
    vector<string> itemList;
    map<string, int>::iterator itStore;
    map<string, int> storeTemp = Store::getStoreData();
    Item *item;
    int num = 1;
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 15);
    for (itStore = storeTemp.begin(); itStore != storeTemp.end(); itStore++) {
        if (itStore->second == 0) {
            continue;
        }
        item = Item::getItemData()[itStore->first];
        sc << num << ". " << itStore->first << " - " << item->getPrice() << " (" << itStore->second << ")" << endl;
        itemList.push_back(itStore->first);
        num++;
    }

    map<string, Item*>::iterator itItem;
    map<string, Item*> itemTemp = Item::getItemData();
    for (itItem = itemTemp.begin(); itItem != itemTemp.end(); itItem++) {
        sc << num << ". " << itItem->first << " - " << itItem->second->getPrice() << endl;
        itemList.push_back(itItem->first);
        num++;
    }
    sc.resetMult();
    sc.resetDelay();

    sc << endl << BOLD MAGENTA << "Uang Anda: " << BOLD YELLOW << this->money << endl;
    sc << BOLD MAGENTA << "Slot penyimpanan tersedia: " << BOLD YELLOW << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << BOLD GREEN << "Barang yang ingin dibeli: " << RESET;
        cin >> buy;
        sc << BOLD GREEN << "Kuantitas: " << RESET;
        cin >> q;

        try {
            if (buy <= 0 || buy >= int(itemList.size()-1)) {
                throw vectorOutOfRangeException();
            }
            else if (this->money < Item::getItemData()[itemList.at(buy-1)]->getPrice() * q) {
                throw moneyNotEnoughException();
            }
            else if (this->inventory.getEmptySlotsCount() < q) {
                throw storageNotEnoughException();
            }
            else if (storeTemp[itemList.at(buy-1)] < q) {
                throw storeStockNotEnoughException();
            }
            valid = true;
        }
        catch (vectorOutOfRangeException e) {
            sc << e.what() << endl;
            sc << BOLD RED << "Masukkan barang yang ingin dibeli diantara" << BOLD YELLOW << "1" << BOLD RED << " sampai " << BOLD YELLOW << itemList.size() << RESET << endl;
        }
        catch (moneyNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storageNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storeStockNotEnoughException e) {
            sc << e.what() << endl;
        }
    }

    this->money -= Item::getItemData()[itemList.at(buy-1)]->getPrice();
    sc << BOLD MAGENTA << "Selamat Anda berhasil membeli " << BOLD YELLOW << q << " " << BOLD YELLOW << itemList.at(buy-1) << "." << BOLD GREEN << " Uang Anda tersisa " << BOLD YELLOW << this->money << endl << endl;

    sc << BOLD YELLOW << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;


    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Petak slot: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << BOLD RED << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << RESET << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            try {
                bool occupied = false;
                for (int i = 0; i < int(slots.size()); i++) {
                    if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                        sc << BOLD RED << "Slot " << BOLD YELLOW << slots.at(i) << BOLD RED << " telah diambil" << RESET << endl;
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
            catch (invalidSlotException e) {
                sc << e.what() << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
            catch (invalid_argument &e) {
                sc << BOLD RED << "Slot yang Anda masukkan tidak valid!" << RESET << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
        }
    }

    for (int i = 0; i < int(slots.size()); i++) {
        this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
    }

    if (Store::getStoreData().count(itemList.at(buy-1)) > 0) {
        Store::reduceStoreData(itemList.at(buy-1), q);
    }
    sc << Item::getItemData()[itemList.at(buy-1)]->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
}

void Peternak::beli() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD MAGENTA << "Selamat datang di toko!!" << endl; sc.setMult(0);
    sc << BOLD GREEN << "Berikut merupakan benda yang dapat Anda Beli" << endl;
    vector<string> itemList;
    map<string, int>::iterator itStore;
    map<string, int> storeTemp = Store::getStoreData();
    Item *item;
    int num = 1;
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 15);
    for (itStore = storeTemp.begin(); itStore != storeTemp.end(); itStore++) {
        if (itStore->second == 0) {
            continue;
        }
        item = Item::getItemData()[itStore->first];
        sc << num << ". " << itStore->first << " - " << item->getPrice() << " (" << itStore->second << ")" << endl;
        itemList.push_back(itStore->first);
        num++;
    }

    map<string, Item*>::iterator itItem;
    map<string, Item*> itemTemp = Item::getItemData();
    for (itItem = itemTemp.begin(); itItem != itemTemp.end(); itItem++) {
        sc << num << ". " << itItem->first << " - " << itItem->second->getPrice() << endl;
        itemList.push_back(itItem->first);
        num++;
    }
    sc.resetMult();
    sc.resetDelay();

    sc << endl << BOLD MAGENTA << "Uang Anda: " << BOLD YELLOW << this->money << endl;
    sc << BOLD MAGENTA << "Slot penyimpanan tersedia: " << BOLD YELLOW << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << BOLD GREEN << "Barang yang ingin dibeli: " << RESET;
        cin >> buy;
        sc << BOLD GREEN << "Kuantitas: " << RESET;
        cin >> q;

        try {
            if (buy <= 0 || buy >= int(itemList.size()-1)) {
                throw vectorOutOfRangeException();
            }
            else if (this->money < Item::getItemData()[itemList.at(buy-1)]->getPrice() * q) {
                throw moneyNotEnoughException();
            }
            else if (this->inventory.getEmptySlotsCount() < q) {
                throw storageNotEnoughException();
            }
            else if (storeTemp[itemList.at(buy-1)] < q) {
                throw storeStockNotEnoughException();
            }
            valid = true;
        }
        catch (vectorOutOfRangeException e) {
            sc << e.what() << endl;
            sc << BOLD RED << "Masukkan barang yang ingin dibeli diantara" << BOLD YELLOW << "1" << BOLD RED << " sampai " << BOLD YELLOW << itemList.size() << RESET << endl;
        }
        catch (moneyNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storageNotEnoughException e) {
            sc << e.what() << endl;
        }
        catch (storeStockNotEnoughException e) {
            sc << e.what() << endl;
        }
    }

    this->money -= Item::getItemData()[itemList.at(buy-1)]->getPrice();
    sc << BOLD MAGENTA << "Selamat Anda berhasil membeli " << BOLD YELLOW << q << " " << BOLD YELLOW << itemList.at(buy-1) << "." << BOLD GREEN << " Uang Anda tersisa " << BOLD YELLOW << this->money << endl << endl;

    sc << BOLD YELLOW << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;


    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Petak slot: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << BOLD RED << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << RESET << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            try {
                bool occupied = false;
                for (int i = 0; i < int(slots.size()); i++) {
                    if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                        sc << BOLD RED << "Slot " << BOLD YELLOW << slots.at(i) << BOLD RED << " telah diambil" << RESET << endl;
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
            catch (invalidSlotException e) {
                sc << e.what() << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
            catch (invalid_argument &e) {
                sc << BOLD RED << "Slot yang Anda masukkan tidak valid!" << RESET << endl;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                goto petak;
            }
        }
    }

    for (int i = 0; i < int(slots.size()); i++) {
        this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
    }

    if (Store::getStoreData().count(itemList.at(buy-1)) > 0) {
        Store::reduceStoreData(itemList.at(buy-1), q);
    }
    sc << Item::getItemData()[itemList.at(buy-1)]->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
}