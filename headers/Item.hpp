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

        virtual ostream& printDetails(ostream& out);
        friend ostream& operator<<(ostream& out, Item* x);
};

class Product : public Item {
    friend class FileManager;

    protected:
        static vector<Product*> ProductData;

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

        static vector<Product*> getProductData() {
            return Product::ProductData;
        }

        friend ostream& operator<<(ostream&, Product);
};

class Building : public Item {
    friend class FileManager;

    protected:
        static vector<Building*> BuildingData;

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

        static vector<Building*> getBuildingData() {
            return Building::BuildingData;
        }

        friend ostream& operator<<(ostream&, Building);
};

#endif