#include "lib/Inventory.hpp"

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

map<int, string> Inventory::intToChar = {
    {0, "A"},
    {1, "B"},
    {2, "C"},
    {3, "D"},
    {4, "E"},
    {5, "F"},
    {6, "G"},
    {7, "H"},
    {8, "I"},
    {9, "J"},
    {10, "K"},
    {11, "L"},
    {12, "M"},
    {13, "N"},
    {14, "O"},
    {15, "P"},
    {16, "Q"},
    {17, "R"},
    {18, "S"},
    {19, "T"},
    {20, "U"},
    {21, "V"},
    {22, "W"},
    {23, "X"},
    {24, "Y"},
    {25, "Z"}
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

string Inventory::getColString(int i) {
    return intToChar[i];
}

string Inventory::getRowString(int i) {
    string add = string(1, '0');
    if (i < 10) return add + to_string(i + 1);
    else return to_string(i + 1);
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

void Inventory::operator+=(Item* I) {
    this->insertItem(I);
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

void Inventory::InsertItemAt(Item* I, string slot) {
    int row = getRow(slot);
    int col = getCol(slot);
    
    this->storage.insert(make_pair(slot, I));
    this->data[row][col] = true;
    this->empty_slots--;
}

void Inventory::insertItem(Item* I) {
    string empty = this->getEmptySlot();

    if (empty != "") this->InsertItemAt(I, empty);
}

Item* Inventory::getItem(string slot) {
    return this->storage[slot];
}

map<string, Item*> Inventory::getAllItems() {
    return this->storage;
}

// ========================================================
// ======================= Farm ===========================
// ========================================================
Farm::Farm() : Inventory(FarmRows, FarmCols) {}

// ========================================================
// ======================= Barn ===========================
// ========================================================
Barn::Barn() : Inventory(BarnRows, BarnCols) {}