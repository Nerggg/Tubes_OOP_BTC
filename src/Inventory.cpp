#include "lib/Inventory.hpp"
#include <iomanip>
#include "lib/colors.h"

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

map<int, string> InventoryContainer::intToChar = {
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

string InventoryContainer::getColString(int i) {
    return intToChar[i];
}

string InventoryContainer::getRowString(int i) {
    string add = string(1, '0');
    if (i < 10) return add + to_string(i + 1);
    else return to_string(i + 1);
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

template <class T>
void Inventory<T>::printInventory(){
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 12);

    int lineLength = this->cols * 6;
    string title = " Penyimpanan ";
    int totalPadding = lineLength - title.length();
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    title = string(4, ' ') + string(leftPadding, '=') + title + string(rightPadding, '=');
    sc << title << endl;

    sc << " ";
    for (int i = 0; i < this->cols; i++){
        sc << "     " << getColString(i);
    }
    sc << "   " << endl;

    for (int i = 0; i < this->rows; i++) {
        sc << "   +-----";
        for (int j = 0; j < this->cols - 1; ++j) {
            sc << "+-----";
        }
        sc << "+" << endl;

        cout << setw(2) << setfill('0') << i + 1;
        cout << " |";

        for (int j = 0; j < this->cols; ++j) {
            string key = getColString(j) + getRowString(i);
            if (storage.find(key) != storage.end()) {
                cout << " " << BOLD CYAN << storage[key]->getCode() << BOLD YELLOW << " |";
            } else {
                cout << "     |"; 
            }
        }
        cout << endl;
    }

    sc << "   +-----";
    for (int j = 0; j < this->cols - 1; ++j) {
        sc << "+-----";
    }
    sc << "+" << endl;

    sc.resetMult();
    sc.resetDelay();

    int emptySlots = getEmptySlotsCount();
    sc << BOLD CYAN << "Total slot kosong: " << BOLD YELLOW << emptySlots << endl;
}

template<>
void Inventory<Plant>::printInventory(){
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 12);

    int lineLength = this->cols * 6;
    string title = " Ladang ";
    int totalPadding = lineLength - title.length();
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    title = string(4, ' ') + string(leftPadding, '=') + title + string(rightPadding, '=');
    sc << title << endl;

    sc << " ";
    for (int i = 0; i < this->cols; i++){
        cout << "     " << getColString(i);
    }
    sc << "   " << endl;

    for (int i = 0; i < this->rows; i++) {
        sc << "   +-----";
        for (int j = 0; j < this->cols - 1; ++j) {
            sc << "+-----";
        }
        sc << "+" << endl;

        cout << setw(2) << setfill('0') << i + 1 << " |";

        for (int j = 0; j < this->cols; ++j) {
            string key = getColString(j) + getRowString(i);
            if (storage.find(key) != storage.end()) {
                if (storage[key]->getAge() < storage[key]->getHarvestAge()) {
                    cout << BOLD RED << " " << storage[key]->getCode() << RESET << BOLD YELLOW << " |";
                } else {
                    cout << BOLD GREEN << " " << storage[key]->getCode() << RESET << BOLD YELLOW << " |";
                }
            } else {
                cout << "     |"; 
            }
        }
        cout << endl;
    }

    sc << "   +-----";
    for (int j = 0; j < this->cols - 1; ++j) {
        sc << "+-----";
    }
    sc << "+" << endl;

    sc.resetMult();
    sc.resetDelay();

    for (const auto& pair : storage) {
        sc << BOLD CYAN << " - " << pair.second->getCode() << ": " << BOLD YELLOW << pair.second->getName() << endl;
    }

}


template<>
void Inventory<Animal>::printInventory(){
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());
    sc.setMult(0);
    sc.setDelay(sc.getDelay() - 12);

    int lineLength = this->cols * 6;
    string title = " Peternakan ";
    int totalPadding = lineLength - title.length();
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    title = string(4, ' ') + string(leftPadding, '=') + title + string(rightPadding, '=');
    sc << title << endl;

    sc << " ";
    for (int i = 0; i < this->cols; i++){
        sc << "     " << getColString(i);
    }
    sc << "   ";
    sc << endl;

    for (int i = 0; i < this->rows; i++) {
        sc << "   +-----";
        for (int j = 0; j < this->cols - 1; ++j) {
            sc << "+-----";
        }
        sc << "+" << endl;

        cout << setw(2) << setfill('0') << i + 1 << " |";

        for (int j = 0; j < this->cols; ++j) {
            string key = getColString(j) + getRowString(i);
            if (storage.find(key) != storage.end()) {
                if (storage[key]->getWeight() < storage[key]->getHarvestWeight()) {
                    cout << BOLD RED << " " << storage[key]->getCode() << RESET << BOLD YELLOW << " |";
                } else {
                    cout << BOLD GREEN << " " << storage[key]->getCode() << RESET << BOLD YELLOW << " |";
                }
            } else {
                cout << "     |"; 
            }
        }
        cout << endl;
    }

    sc << "   +-----";
    for (int j = 0; j < this->cols - 1; ++j) {
        sc << "+-----";
    }
    sc << "+" << endl;

    sc.resetMult();
    sc.resetDelay();
    
    for (const auto& pair : storage) {
        sc << BOLD CYAN << " - " << pair.second->getCode() << ": " << BOLD YELLOW << pair.second->getName() << endl;
    }

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
int Inventory<T>::countItem(string code){
    int count =0;
    for(const auto&pair : this->getAllItems()){
        if(pair.second.code = code){
            count++;
        }
    }
}

template <class T>
T* Inventory<T>::getItem(string slot) {
    // potential bug because [] operator can mutate the map by generating the item if it doesnt exist in the map.
    // return storage[slot];
    // so we use at() instead
    auto it = storage.find(slot);
    if (it != storage.end()) {
        return it->second;
    }
    else {
        return NULL;
    }
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

template <class T>
map<string, T*>& Inventory<T>::getAllItems() {
    return storage;
}

template <class T>
bool Inventory<T>::cekSlot(string slot) {
    int row = getRow(slot);
    int col = getCol(slot);
    return data[row][col];
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

template <class T>
void Inventory<T>::DeleteItemAt(string slot) {
    int row = getRow(slot);
    int col = getCol(slot);
    storage.erase(slot);
    data[row][col] = false;
    empty_slots++;
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