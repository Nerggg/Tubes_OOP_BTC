#ifndef __STORE_HPP
#define __STORE_HPP

#include "Item.hpp"

class Store {
    friend class FileManager;
    private:
        static map<string, int> StoreData;

    public:
};

#endif