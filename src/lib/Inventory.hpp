#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

#include <vector>
#include <map>

#include "Item.hpp"
#include "Plant.hpp"
#include "Animal.hpp"

using namespace std;

class InventoryContainer
{
    friend class FileManager;
    friend class Peternak;
    friend class Petani;

protected:
    // Static variables
    static int InventoryRows;
    static int InventoryCols;

    static int FarmRows;
    static int FarmCols;

    static int BarnRows;
    static int BarnCols;

    static map<string, int> charToInt;
    static map<int, string> intToChar;

    // Static methods
    static int getCol(string);
    static int getRow(string);
    static string getColString(int);
    static string getRowString(int);
};

template <class T>
class Inventory : public InventoryContainer {
protected:
    // Instance variables
    vector<vector<bool>> data;
    map<string, T *> storage;
    int rows;
    int cols;
    int empty_slots;

public:
    // Constructors
    Inventory();
    Inventory(int, int);

    // Printers
    template <class U>
    friend ostream &operator<<(ostream &out, Inventory<U> &inv);

    void printInventory();

    // Getters
    virtual int getInvRows();
    virtual int getInvCols();
    int getEmptySlotsCount();
    int getUsedSlotsCount();

    T *getItem(string);
    string getEmptySlot();

    map<string, T *> &getAllItems();
    bool cekSlot(string);
    int countItem(string);

    // Setter
    void InsertItemAt(T *, string);
    void insertItem(T *);
    void DeleteItemAt(string);

    // Operator Overloads
    void operator+=(T *);

    // Instance methods
};

#endif