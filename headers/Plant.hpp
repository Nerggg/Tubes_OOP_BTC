#ifndef __PLANT_HPP
#define __PLANT_HPP

#include "Item.hpp"

class Plant : public Item {
    friend class FileManager;

    protected:
        static map<string, Plant*> PlantData; 
        
        int harvestAge;
        int age;
        
    public:
        Plant();
        Plant(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestAge, 
            int price, 
            string itemType
        );
        Plant(const Plant&);
        void printName() const {
            cout << this->id << ' ';
            cout << this->code << ' ';
            cout << this->name << ' ';
            cout << this->type << ' ';
            cout << this->harvestAge << ' ';
            cout << this->price << ' ';
            cout << this->itemType << ' ';
            cout << endl;
        };

        static map<string, Plant*> getPlantData() {
            return Plant::PlantData;
        }

        ostream& printDetails(ostream&);
        friend ostream& operator<<(ostream&, Plant*);
};

#endif