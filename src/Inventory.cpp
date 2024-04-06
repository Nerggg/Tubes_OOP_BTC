#include "lib/Inventory.hpp"
#include <iomanip>

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
    {"Z", 25}};

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
    {25, "Z"}};

// ========================================================
// ==================== Constructors ======================
// ========================================================

template <class T>
Inventory<T>::Inventory() : Inventory<T>(InventoryRows, InventoryCols)
{
}

template <class T>
Inventory<T>::Inventory(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        // Initialize row vector
        vector<bool> v;

        // Fill row vector
        for (int j = 0; j < c; j++)
        {
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

int InventoryContainer::getCol(string s)
{
    string key = string(1, s[0]);
    return charToInt[key];
}

int InventoryContainer::getRow(string s)
{
    return stoi(s.substr(1)) - 1;
}

string InventoryContainer::getColString(int i)
{
    return intToChar[i];
}

string InventoryContainer::getRowString(int i)
{
    string add = string(1, '0');
    if (i < 10)
        return add + to_string(i + 1);
    else
        return to_string(i + 1);
}

// ========================================================
// ======================= Printers =======================
// ========================================================
template <class T>
ostream &operator<<(ostream &out, Inventory<T> &inv)
{
    for (auto row : inv.data)
    {
        for (auto col : row)
        {
            out << col << " ";
        }
        out << endl;
    }
    out << endl;

    return out;
}

template <class T>
void Inventory<T>::printInventory()
{
    cout << " ";
    for (int i = 0; i < this->cols; i++)
    {
        cout << "     " << getColString(i);
    }
    cout << "   ";
    cout << endl;

    for (int i = 0; i < this->rows; i++)
    {
        cout << "   +-----";
        for (int j = 0; j < this->cols - 1; ++j)
        {
            cout << "+-----";
        }
        cout << "+";
        cout << endl;

        cout << setw(2) << i + 1 << " |"; // Row number

        for (int j = 0; j < this->cols; ++j)
        {
            string key = getRowString(i) + getColString(j);
            if (storage.find(key) != storage.end())
            {
                cout << " " << storage[key]->getId() << " |"; // ID of item
            }
            else
            {
                cout << "     |";
            }
        }
        cout << endl;
    }

    cout << "   +-----";
    for (int j = 0; j < this->cols - 1; ++j)
    {
        cout << "+-----";
    }
    cout << "+";
    cout << endl;

    int emptySlots = getEmptySlotsCount();
    cout << "Total slot kosong: " << emptySlots << endl;
}

// ========================================================
// ======================= Getters ========================
// ========================================================

template <class T>
int Inventory<T>::getInvRows()
{
    return rows;
}

template <class T>
int Inventory<T>::getInvCols()
{
    return cols;
}

template <class T>
int Inventory<T>::getEmptySlotsCount()
{
    return empty_slots;
}

template <class T>
T *Inventory<T>::getItem(string slot)
{
    return storage[slot];
}

template <class T>
string Inventory<T>::getEmptySlot()
{
    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        for (const auto &pair : charToInt)
        {
            if (j >= cols)
            {
                break;
            }

            string ch = pair.first;
            int c = pair.second;

            if (data[i][c] == false)
            {
                i++;
                string r = (i < 10) ? "0" + to_string(i) : to_string(i);
                return ch.append(r);
            }
        }
    }

    return "";
}

template <class T>
map<string, T *> &Inventory<T>::getAllItems()
{
    return storage;
}

template <class T>
bool Inventory<T>::cekSlot(string slot)
{
    int row = getRow(slot);
    int col = getCol(slot);
    return data[row][col];
}

// ========================================================
// ======================= Setters ========================
// ========================================================

template <class T>
void Inventory<T>::InsertItemAt(T *I, string slot)
{
    int row = getRow(slot);
    int col = getCol(slot);

    storage.insert(make_pair(slot, I));
    data[row][col] = true;
    empty_slots--;
}

template <class T>
void Inventory<T>::insertItem(T *I)
{
    string empty = getEmptySlot();

    if (empty != "")
        InsertItemAt(I, empty);
}

template <class T>
void Inventory<T>::DeleteItemAt(string slot)
{
    int row = getRow(slot);
    int col = getCol(slot);
    storage.erase(slot);
    data[row][col] = false;
    empty_slots++;
}

template <class T>
int Inventory<T>::countItem(string name)
{
    // count number of specific item in inventory based on the item code with the asumption that every item has a unique code.

    // not tested yet

    int count = 0;
    for (const auto &pair : storage)
    {
        if (name = pair.second.getName())
        {
            count++;
        }
    }
    return count;
}

// ========================================================
// ================== Operator Overloads ==================
// ========================================================
template <class T>
void Inventory<T>::operator+=(T *I)
{
    insertItem(I);
}

// ========================================================
// =================== Instance Methods ===================
// ========================================================

template class Inventory<Item>;
template class Inventory<Animal>;
template class Inventory<Plant>;