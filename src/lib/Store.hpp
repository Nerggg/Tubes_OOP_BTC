#ifndef __STORE_HPP
#define __STORE_HPP

#include "Item.hpp"

class Store {
    friend class FileManager;
    private:
        // Static variables
        static map<string, int> StoreData;
        
        // Instance variables

    public:
        // Static methods

        // Printers

        // Getters
        static map<string, int> getStoreData() {
            return Store::StoreData;
        }

        // Setters

        // Instance methods
};

#endif