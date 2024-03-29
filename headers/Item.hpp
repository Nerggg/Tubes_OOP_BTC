#ifndef __ITEM_HPP
#define __ITEM_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class Item {
    friend class FileManager;
    // friend ostream& operator<<(ostream&, Item);

    protected:
        int id;
        string code;
        string name;
        string type;
        int price;
        
        string itemType;

        static map<string, Item*> ItemData;

    public:
        Item();
        Item(
            int id, 
            string code, 
            string name, 
            string type, 
            int price, 
            string itemType
        );

        string getName();

        virtual ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Item* x);

        static map<string, Item*> getItemData() {
            return Item::ItemData;
        }

        virtual Item* clone() = 0;
};

class Product : public Item {
    friend class FileManager;

    protected:
        static map<string, Product*> ProductData;

        string origin;
        int addedWeight;

    public:
        Product();
        Product(
            int id, 
            string code, 
            string name, 
            string type,
            string origin, 
            int addedWeight, 
            int price, 
            string itemType
        );
        Product(const Product&);

        static map<string, Product*> getProductData() {
            return Product::ProductData;
        }

        // friend ostream& operator<<(ostream&, Product);
        ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Product* x);

        Item* clone();
};

class Building : public Item {
    friend class FileManager;

    protected:
        static map<string, Building*> BuildingData;

        map<string, int> recipe;

    public:
        Building();
        Building(
            int id, 
            string code, 
            string name, 
            string type, 
            int price,
            map<string, int> recipe, 
            string itemType
        );
        Building(const Building&);

        static map<string, Building*> getBuildingData() {
            return Building::BuildingData;
        }

        // friend ostream& operator<<(ostream&, Building);
        ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Building* x);

        Item* clone();
};

#endif