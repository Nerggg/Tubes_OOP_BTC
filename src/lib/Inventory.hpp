#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

#include <vector>
#include <map>

#include "Item.hpp"
#include "Plant.hpp"
#include "Animal.hpp"

using namespace std;

class Inventory {
    friend class FileManager;
    protected:
        // Static variables
        static int InventoryRows;
        static int InventoryCols;
        static map<string, int> charToInt;

        // Instance variables
        vector<vector<bool>> data;
        map<string, Item*> storage;
        int empty_slots;

    public:
        // Constructors
        Inventory();
        Inventory(int, int);

        // Static methods
        static int getCol(string);
        static int getRow(string);

        // Printers
        friend ostream& operator<<(ostream& out, Inventory& inv) {
            for (auto row : inv.data) {
                for (auto col : row) {
                    out << col << " ";
                }
                out << endl;
            }
            out << endl;

            return out;
        }

        // Getters
        virtual int getInvRows() {
            return Inventory::InventoryRows;
        }
        virtual int getInvCols() {
            return Inventory::InventoryCols;
        }
        int getEmptySlotsCount() {
            return this->empty_slots;
        }
        Item* getItem(string);
        string getEmptySlot();

        // Instance methods
        void operator+=(Item*);

        void InsertItemAt(Item*, string);
        void insertItem(Item*);
};

class Farm : public Inventory {
    friend class FileManager;

    protected:
        // Static variables
        static int FarmRows;
        static int FarmCols;

        // Instance variables
    
    public:
        // Constructors
        Farm();

        // Getters
        int getInvRows() {
            return Farm::FarmRows;
        }
        int getInvCols() {
            return Farm::FarmCols;
        }

        // Instance methods
};

class Barn : public Inventory {
    friend class FileManager;

    protected:
        // Static variables
        static int BarnRows;
        static int BarnCols;

        // Instance variables

    public:
        // Constructors
        Barn();

        // Getters
        int getInvRows() {
            return Barn::BarnRows;
        }
        int getInvCols() {
            return Barn::BarnCols;
        }

        // Instance methods
};

#endif