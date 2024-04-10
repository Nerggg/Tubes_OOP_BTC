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
    sc << "Selamat datang di toko!!" << endl;
    sc << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    vector<string> itemList;
    map<string, int>::iterator itStore;
    map<string, int> storeTemp = Store::getStoreData();
    Item *item;
    int num = 1;
    for (itStore = storeTemp.begin(); itStore != storeTemp.end(); itStore++) {
        if (itStore->second == 0 || Item::getItemData()[itStore->first]->isBuilding()) {
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

    sc << endl << "Uang Anda: " << this->money << endl;
    sc << "Slot penyimpanan tersedia: " << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << "Barang yang ingin dibeli: ";
        cin >> buy;
        sc << "Kuantitas: ";
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
            sc << "Masukkan barang yang ingin dibeli diantara 1 sampai " << itemList.size() << endl;
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
    sc << "Selamat Anda berhasil membeli " << q << " " << itemList.at(buy-1) << ". Uang Anda tersisa " << this->money << endl << endl;

    sc <<  "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;

    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << "Petak slot: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            bool occupied = false;
            for (int i = 0; i < int(slots.size()); i++) {
                if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                    sc << "Slot " << slots.at(i) << " telah diambil" << endl;
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

    try {
        for (int i = 0; i < int(slots.size()); i++) {
            this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
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
        sc << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
    }

    if (Store::getStoreData().count(itemList.at(buy-1)) > 0) {
        Store::reduceStoreData(itemList.at(buy-1), q);
    }
    sc << Item::getItemData()[itemList.at(buy-1)]->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
}

void Petani::beli() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << "Selamat datang di toko!!" << endl;
    sc << "Berikut merupakan hal yang dapat Anda Beli" << endl;
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

    sc << endl << "Uang Anda: " << this->money << endl;
    sc << "Slot penyimpanan tersedia: " << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << "Barang yang ingin dibeli: ";
        cin >> buy;
        sc << "Kuantitas: ";
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
            sc << "Masukkan barang yang ingin dibeli diantara 1 sampai " << itemList.size() << endl;
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
    sc << "Selamat Anda berhasil membeli " << q << " " << itemList.at(buy-1) << ". Uang Anda tersisa " << this->money << endl << endl;

    sc <<  "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;

    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << "Petak slot: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            bool occupied = false;
            for (int i = 0; i < int(slots.size()); i++) {
                if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                    sc << "Slot " << slots.at(i) << " telah diambil" << endl;
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

    try {
        for (int i = 0; i < int(slots.size()); i++) {
            this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
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
        sc << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
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
    sc << "Selamat datang di toko!!" << endl;
    sc << "Berikut merupakan hal yang dapat Anda Beli" << endl;
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

    sc << endl << "Uang Anda: " << this->money << endl;
    sc << "Slot penyimpanan tersedia: " << this->inventory.getEmptySlotsCount() << endl << endl;

    int buy;
    int q;
    bool valid = false;

    while (!valid) {
        sc << "Barang yang ingin dibeli: ";
        cin >> buy;
        sc << "Kuantitas: ";
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
            sc << "Masukkan barang yang ingin dibeli diantara 1 sampai " << itemList.size() << endl;
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
    sc << "Selamat Anda berhasil membeli " << q << " " << itemList.at(buy-1) << ". Uang Anda tersisa " << this->money << endl << endl;

    sc <<  "Pilih slot untuk menyimpan barang yang Anda beli!" << endl << endl;

    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    valid = false;
    while (!valid) {
        sc << "Petak slot: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }

        if (int(slots.size()) != q) {
            sc << "Tolong masukkan jumlah slot yang sesuai dengan jumlah barang yang kamu beli" << endl;
            while (!slots.empty()) {
                slots.pop_back();
            }
        }
        else {
            bool occupied = false;
            for (int i = 0; i < int(slots.size()); i++) {
                if (this->inventory.getSlotStatus(slots.at(i)) != NULL) {
                    sc << "Slot " << slots.at(i) << " telah diambil" << endl;
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

    try {
        for (int i = 0; i < int(slots.size()); i++) {
            this->inventory.InsertItemAt(Item::getItemData()[itemList.at(buy-1)], slots.at(i));
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
        sc << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
    }

    if (Store::getStoreData().count(itemList.at(buy-1)) > 0) {
        Store::reduceStoreData(itemList.at(buy-1), q);
    }
    sc << Item::getItemData()[itemList.at(buy-1)]->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
}