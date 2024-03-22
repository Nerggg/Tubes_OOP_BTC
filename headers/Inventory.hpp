#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

class Inventory {
    protected:
        static int StorageRows;
        static int StorageCols;

    public:
};

class Farm : public Inventory {
    protected:
        static int FarmRows;
        static int FarmCols;

};

class Barn : public Inventory {
    protected:
        static int BarnRows;
        static int BarnCols;
};

#endif