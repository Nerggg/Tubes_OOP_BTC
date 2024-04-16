#include "../lib/Player.hpp"
#include "../lib/Store.hpp"
#include <sstream>

// ========================================================
// ======================== JUAL ==========================
// ========================================================

void Walikota::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD CYAN << "Berikut merupakan penyimpanan Anda" << RESET << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    int profit = 0;
    try {
    bool valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty = false;

        for (int i = 0; i < int(slots.size()); i++) {
            if (this->inventory.getSlotStatus(slots.at(i)) == NULL) {
                sc << BOLD RED << "Slot " << slots.at(i) << " kosong" << endl;
                empty = true;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                break;
            }
        }
        if (empty == false) {
            valid = true;
        }
    }

    Item* itemTemp;

        for (int i = 0; i < int(slots.size()); i++) {
            itemTemp = this->inventory.getItem(slots.at(i));
            this->inventory.DeleteItemAt(slots.at(i));
            Store::addStoreData(itemTemp->getName());
            this->money += itemTemp->getPrice();
            profit += itemTemp->getPrice();
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
        sc << BOLD RED << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
    }

    sc << BOLD MAGENTA << "Barang Anda berhasil dijual! Uang Anda bertambah " << BOLD YELLOW << profit << BOLD MAGENTA << " gulden!" << RESET << endl;
}

void Petani::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD CYAN << "Berikut merupakan penyimpanan Anda" << RESET << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    int profit = 0;
    try {
    bool valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty = false;

        for (int i = 0; i < int(slots.size()); i++) {
            if (this->inventory.getSlotStatus(slots.at(i)) == NULL) {
                sc << BOLD RED << "Slot " << slots.at(i) << " kosong" << endl;
                empty = true;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                break;
            }
        }
        if (empty == false) {
            valid = true;
        }
    }

    Item* itemTemp;

        for (int i = 0; i < int(slots.size()); i++) {
            itemTemp = this->inventory.getItem(slots.at(i));
            this->inventory.DeleteItemAt(slots.at(i));
            Store::addStoreData(itemTemp->getName());
            this->money += itemTemp->getPrice();
            profit += itemTemp->getPrice();
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
        sc << BOLD RED << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
    }

    sc << BOLD MAGENTA << "Barang Anda berhasil dijual! Uang Anda bertambah " << BOLD YELLOW << profit << BOLD MAGENTA << " gulden!" << RESET << endl;
}

void Peternak::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD CYAN << "Berikut merupakan penyimpanan Anda" << RESET << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

petak:
    int profit = 0;
    try {
    bool valid = false;
    while (!valid) {
        sc << BOLD GREEN << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: " << RESET;
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty = false;

        for (int i = 0; i < int(slots.size()); i++) {
            if (this->inventory.getSlotStatus(slots.at(i)) == NULL) {
                sc << BOLD RED << "Slot " << slots.at(i) << " kosong" << endl;
                empty = true;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                break;
            }
        }
        if (empty == false) {
            valid = true;
        }
    }

    Item* itemTemp;

        for (int i = 0; i < int(slots.size()); i++) {
            itemTemp = this->inventory.getItem(slots.at(i));
            this->inventory.DeleteItemAt(slots.at(i));
            Store::addStoreData(itemTemp->getName());
            this->money += itemTemp->getPrice();
            profit += itemTemp->getPrice();
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
        sc << BOLD RED << "Slot yang Anda masukkan tidak valid" << endl;
        while (!slots.empty()) {
            slots.pop_back();
        }
        goto petak;
    }

    sc << BOLD MAGENTA << "Barang Anda berhasil dijual! Uang Anda bertambah " << BOLD YELLOW << profit << BOLD MAGENTA << " gulden!" << RESET << endl;
}