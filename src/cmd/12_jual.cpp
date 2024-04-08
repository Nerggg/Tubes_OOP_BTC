#include "../lib/Player.hpp"

// ========================================================
// ======================== JUAL ==========================
// ========================================================

void Walikota::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << "Berikut merupakan penyimpanan Anda" << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

    bool valid = false;
    while (!valid) {
        sc << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty;
        for (int i = 0; i < slots.size(); i++) {
            if (this->inventory.getItem(slots.at(i)) == NULL) {
                sc << "Slot " << slots.at(i) << " kosong" << endl;
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

    int profit = 0;
    for (int i = 0; i < slots.size(); i++) {
        this->money += this->inventory.getItem(slots.at(i))->getPrice();
        profit += this->inventory.getItem(slots.at(i))->getPrice();
        this->inventory.DeleteItemAt(slots.at(i));
    }

    sc << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
}

void Petani::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << "Berikut merupakan penyimpanan Anda" << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

    bool valid = false;
    while (!valid) {
        sc << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty;
        for (int i = 0; i < slots.size(); i++) {
            if (this->inventory.getItem(slots.at(i)) == NULL) {
                sc << "Slot " << slots.at(i) << " kosong" << endl;
                empty = true;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                break;
            }
            else if (this->inventory.getItem(slots.at(i))->isBuilding()) {
                sc << "Slot " << slots.at(i) << " adalah bangunan" << endl;
                sc << "Petani tidak bisa menjual bangunan" << endl;
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

    int profit = 0;
    for (int i = 0; i < slots.size(); i++) {
        this->money += this->inventory.getItem(slots.at(i))->getPrice();
        profit += this->inventory.getItem(slots.at(i))->getPrice();
        this->inventory.DeleteItemAt(slots.at(i));
    }

    sc << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
}

void Peternak::jual() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << "Berikut merupakan penyimpanan Anda" << endl;
    this->cetakPenyimpanan();

    vector<string> slots;
    string slotTemp, slotInput;
    getline(cin, slotInput);

    bool valid = false;
    while (!valid) {
        sc << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        sc << "Petak: ";
        getline(cin, slotInput);
        stringstream ss(slotInput);
        while (std::getline(ss, slotTemp, ',')) {
            slotTemp.erase(0, slotTemp.find_first_not_of(' '));
            slotTemp.erase(slotTemp.find_last_not_of(' ') + 1);
            slots.push_back(slotTemp);
        }
        bool empty;
        for (int i = 0; i < slots.size(); i++) {
            if (this->inventory.getItem(slots.at(i)) == NULL) {
                sc << "Slot " << slots.at(i) << " kosong" << endl;
                empty = true;
                while (!slots.empty()) {
                    slots.pop_back();
                }
                break;
            }
            else if (this->inventory.getItem(slots.at(i))->isBuilding()) {
                sc << "Slot " << slots.at(i) << " adalah bangunan" << endl;
                sc << "Peternak tidak bisa menjual bangunan" << endl;
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

    int profit = 0;
    for (int i = 0; i < slots.size(); i++) {
        this->money += this->inventory.getItem(slots.at(i))->getPrice();
        profit += this->inventory.getItem(slots.at(i))->getPrice();
        this->inventory.DeleteItemAt(slots.at(i));
    }

    sc << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
}