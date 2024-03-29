#include "headers/Inventory.hpp"

// Static Attributes
int Inventory::InventoryRows = 0;
int Inventory::InventoryCols = 0;

int Farm::FarmRows = 0;
int Farm::FarmCols = 0;

int Barn::BarnRows = 0;
int Barn::BarnCols = 0;

map<string, int> Inventory::charToInt = {
    {"A", 0},
    {"B", 1},
    {"C", 2},
    {"D", 3},
    {"E", 4},
    {"F", 5},
    {"G", 6},
    {"H", 7},
    {"I", 8},
    {"J", 9},
    {"K", 10},
    {"L", 11},
    {"M", 12},
    {"N", 13},
    {"O", 14},
    {"P", 15},
    {"Q", 16},
    {"R", 17},
    {"S", 18},
    {"T", 19},
    {"U", 20},
    {"V", 21},
    {"W", 22},
    {"X", 23},
    {"Y", 24},
    {"Z", 25}
};

// ========================================================
// ===================== Inventory ========================
// ========================================================
int Inventory::getCol(string s) {
    string key = string(1, s[0]);
    return charToInt[key];
}

int Inventory::getRow(string s) {
    return stoi(s.substr(1)) - 1;
}

Inventory::Inventory() : Inventory(InventoryRows, InventoryCols) {

}

Inventory::Inventory(int r, int c) {
    for (int i = 0; i < r; i++) {
        vector<bool> v;
        
        for (int j = 0; j < c; j++) {
            v.push_back(false);
        }

        this->data.push_back(v);
    }
    this->empty_slots = r * c;
}

string Inventory::getEmptySlot() {
    int rows = this->getInvRows();
    int cols = this->getInvCols();

    for (int i = 0; i < rows; i++) {
        int j = 0;
        for (const auto& pair : charToInt) {
            if (j >= cols) {
                break;
            }

            string ch = pair.first;
            int c = pair.second;

            if (this->data[i][c] == false) {
                i++;
                string r = (i < 10) ? "0" + to_string(i) : to_string(i);
                return ch.append(r);
            }
        }
    }

    return "";
}

void Inventory::insertItem(Item* I) {
    string empty = this->getEmptySlot();
    
    int row = getRow(empty);
    int col = getCol(empty);

    this->storage.insert(make_pair(empty, I));
    this->data[row][col] = true;
    this->empty_slots--;
}

Item* Inventory::getItem(string slot) {
    return this->storage[slot];
}

// ========================================================
// ======================= Farm ===========================
// ========================================================
Farm::Farm() : Inventory(FarmRows, FarmCols) {}

// ========================================================
// ======================= Barn ===========================
// ========================================================
Barn::Barn() : Inventory(BarnRows, BarnCols) {}