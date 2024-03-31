#include "lib/Inventory.hpp"

// Static variables
int InventoryContainer::InventoryRows;
int InventoryContainer::InventoryCols;

int InventoryContainer::FarmRows;
int InventoryContainer::FarmCols;

int InventoryContainer::BarnRows;
int InventoryContainer::BarnCols;

map<string, int> InventoryContainer::charToInt = {
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
// ==================== Constructors ======================
// ========================================================

template <class T>
Inventory<T>::Inventory() : Inventory<T>(InventoryRows, InventoryCols) {

}

template <class T>
Inventory<T>::Inventory(int r, int c) {
    for (int i = 0; i < r; i++) {
        // Initialize row vector
        vector<bool> v;
        
        // Fill row vector
        for (int j = 0; j < c; j++) {
            v.push_back(false);
        }
        
        // Push row vector to matrix
        data.push_back(v);
    }

    // Set instance variables
    rows = r;
    cols = c;
    empty_slots = r * c;
}


// ========================================================
// ==================== Static Methods ====================
// ========================================================

int InventoryContainer::getCol(string s) {
    string key = string(1, s[0]);
    return charToInt[key];
}

int InventoryContainer::getRow(string s){
    return stoi(s.substr(1)) - 1;
}

// ========================================================
// ======================= Printers =======================
// ========================================================
template <class T>
ostream& operator<<(ostream& out, Inventory<T>& inv) {
    for (auto row : inv.data) {
        for (auto col : row) {
            out << col << " ";
        }
        out << endl;
    }
    out << endl;

    return out;
}

// ========================================================
// ======================= Getters ========================
// ========================================================

template <class T>
int Inventory<T>::getInvRows() {
    return rows;
}

template <class T>
int Inventory<T>::getInvCols() {
    return cols;
}

template <class T>
int Inventory<T>::getEmptySlotsCount() {
    return empty_slots;
}

template <class T>
T* Inventory<T>::getItem(string slot) {
    return storage[slot];
}

template <class T>
string Inventory<T>::getEmptySlot() {
    for (int i = 0; i < rows; i++) {
        int j = 0;
        for (const auto& pair : charToInt) {
            if (j >= cols) {
                break;
            }

            string ch = pair.first;
            int c = pair.second;

            if (data[i][c] == false) {
                i++;
                string r = (i < 10) ? "0" + to_string(i) : to_string(i);
                return ch.append(r);
            }
        }
    }

    return "";
}

// ========================================================
// ======================= Setters ========================
// ========================================================

template <class T>
void Inventory<T>::InsertItemAt(T* I, string slot) {
    int row = getRow(slot);
    int col = getCol(slot);
    
    storage.insert(make_pair(slot, I));
    data[row][col] = true;
    empty_slots--;
}

template <class T>
void Inventory<T>::insertItem(T* I) {
    string empty = getEmptySlot();

    if (empty != "") InsertItemAt(I, empty);
}

// ========================================================
// ================== Operator Overloads ==================
// ========================================================
template <class T>
void Inventory<T>::operator+=(T* I) {
    insertItem(I);
}

// ========================================================
// =================== Instance Methods ===================
// ========================================================

template class Inventory<Item>;
template class Inventory<Animal>;
template class Inventory<Plant>;