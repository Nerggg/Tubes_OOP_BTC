#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

class Inventory {
    friend class FileManager;
    friend class Game;
    protected:
        static int InventoryRows;
        static int InventoryCols;

    public:
};

class Farm : public Inventory {
    friend class FileManager;
    friend class Game;
    protected:
        static int FarmRows;
        static int FarmCols;

};

class Barn : public Inventory {
    friend class FileManager;
    friend class Game;
    protected:
        static int BarnRows;
        static int BarnCols;
};

#endif