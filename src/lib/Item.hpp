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
        static map<string, Item*> getItemData();

        // Printers
        virtual ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Item* x);

        virtual SlowPrinter slowPrintDetails(SlowPrinter out);
        friend SlowPrinter operator<<(SlowPrinter out, Item* I);

        // Getters
        int getId();
        string getName();
        string getCode();
        string getType();
        int getPrice();

        // Type checkers
        virtual bool isAnimal() = 0;
        virtual bool isPlant() = 0;
        virtual bool isProduct() = 0;
        virtual bool isBuilding() = 0;
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
        string getOrigin();
        int getAddedWeight();
        
        // Type checkers
        bool isAnimal();
        bool isPlant();
        bool isProduct();
        bool isBuilding();
        bool isEdiblePlant();
        bool isEdibleAnimal();
        
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
        map<string, int> getRecipe();

        // Type checkers
        bool isAnimal();
        bool isPlant();
        bool isProduct();
        bool isBuilding();
                
        // Instance methods

};

#endif