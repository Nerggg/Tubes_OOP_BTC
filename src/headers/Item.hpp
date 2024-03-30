#ifndef __ITEM_HPP
#define __ITEM_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

#include "SlowPrinter.hpp"

using namespace std;

class Item {
    friend class FileManager;

    protected:
        // Static variables
        static map<string, Item*> ItemData;

        // Instance variables
        int id;
        string code;
        string name;
        string type;
        int price;
        
    public:
        // Constructors
        Item();
        Item(
            int id, 
            string code, 
            string name, 
            string type, 
            int price
        );
        
        virtual Item* clone() = 0;

        // Static methods
        static map<string, Item*> getItemData() {
            return Item::ItemData;
        }

        // Printers
        virtual ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Item* x);

        virtual SlowPrinter slowPrintDetails(SlowPrinter out);
        friend SlowPrinter operator<<(SlowPrinter out, Item* I);

        // Getters
        string getName();

};

class Product : public Item {
    friend class FileManager;

    protected:
        // Static variables

        // Instance variables
        string origin;
        int addedWeight;

    public:
        // Constructors
        Product();
        Product(
            int id, 
            string code, 
            string name, 
            string type,
            string origin, 
            int addedWeight, 
            int price
        );
        Product(const Product&);

        Item* clone();

        // Static methods

        // Printers
        ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Product* x);

        SlowPrinter slowPrintDetails(SlowPrinter out);
        friend SlowPrinter operator<<(SlowPrinter, Product*);

        // Getters

        // Instance methods
};

class Building : public Item {
    friend class FileManager;

    protected:
        // Static variables

        // Instance variables
        map<string, int> recipe;

    public:
        // Constructors
        Building();
        Building(
            int id, 
            string code, 
            string name, 
            string type, 
            int price,
            map<string, int> recipe
        );
        Building(const Building&);

        Item* clone();

        // Static methods

        // Printers
        ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Building* x);

        SlowPrinter slowPrintDetails(SlowPrinter out);
        friend SlowPrinter operator<<(SlowPrinter, Building*);

        // Getters

        // Instance methods

};

#endif