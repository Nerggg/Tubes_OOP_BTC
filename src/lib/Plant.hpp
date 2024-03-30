#ifndef __PLANT_HPP
#define __PLANT_HPP

#include "Item.hpp"

class Plant : public Item {
    friend class FileManager;

    protected:
        // Static variables

        // Instance variables         
        int harvestAge;
        int age;
        
    public:
        // Constructors
        Plant();
        Plant(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestAge, 
            int price
        );
        Plant(const Plant&);

        Item* clone();
        
        // Printers
        ostream& printDetails(ostream&);
        friend ostream& operator<<(ostream&, Plant*);

        SlowPrinter slowPrintDetails(SlowPrinter);
        friend SlowPrinter operator<<(SlowPrinter, Plant*);

        // Getters

        // Instance methods

};

#endif