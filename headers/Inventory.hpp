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
    friend class Game;
    friend int main();
    protected:
        static int InventoryRows;
        static int InventoryCols;

        static map<string, int> charToInt;

        vector<vector<bool>> data;
        map<string, Item*> storage;
        int empty_slots;

    public:
        static int getCol(string);
        static int getRow(string);

        Inventory();
        Inventory(int, int);

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

        void operator+=(Item*);

        virtual int getInvRows() {
            return Inventory::InventoryRows;
        }
        virtual int getInvCols() {
            return Inventory::InventoryCols;
        }

        string getEmptySlot();
        void InsertItemAt(Item*, string);
        void insertItem(Item*);
        Item* getItem(string);
};

class Farm : public Inventory {
    friend class FileManager;
    friend class Player;
    friend int main();
    protected:
        static int FarmRows;
        static int FarmCols;
    
    public:
        Farm();

    int getInvRows() {
        return Farm::FarmRows;
    }
    int getInvCols() {
        return Farm::FarmCols;
    }
};

class Barn : public Inventory {
    friend class FileManager;
    friend class Player;
    friend int main();
    protected:
        static int BarnRows;
        static int BarnCols;

    public:
        Barn();

        int getInvRows() {
            return Barn::BarnRows;
        }
        int getInvCols() {
            return Barn::BarnCols;
        }
};

#endif