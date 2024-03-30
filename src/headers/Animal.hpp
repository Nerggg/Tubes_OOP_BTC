#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP

#include "Item.hpp"

#define TYPE_HERBIVORE "HERBIVORE"
#define TYPE_CARNIVORE "CARNIVORE"
#define TYPE_OMNIVORE "OMNIVORE"

class Animal : public Item {
    friend class FileManager;

    protected:
        // Static variables
        static map<string, Animal*> AnimalData;

        // Instance variables
        int harvestWeight;
        int weight;

    public:
        // Constructors
        Animal();
        Animal(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price
        );
        Animal(const Animal&);

        // Static methods
        static map<string, Animal*> getAnimalData() {
            return Animal::AnimalData;
        
        };

        // Printers
        ostream& printDetails(ostream&);
        friend ostream& operator<<(ostream&, Animal*);

        SlowPrinter slowPrintDetails(SlowPrinter);
        friend SlowPrinter operator<<(SlowPrinter, Animal*);

        // Instance methods
        virtual void feed(Item*) = 0;
};

class Herbivore : public Animal {
    public:
        // Constructors
        Herbivore(
            int id, 
            string code,
            string name, 
            string type, 
            int harvestWeight, 
            int price
        );
        Herbivore(const Herbivore&);
        
        Item* clone();
        
        // Instance methods
        void feed(Item*);
};

class Carnivore : public Animal {
    public:
        // Constructors
        Carnivore(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price
        );
        Carnivore(const Carnivore&);
        
        Item* clone();
        
        // Instance methods
        void feed(Item*);
};

class Omnivore : public Animal {
    public:
        // Constructors
        Omnivore(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price
        );
        Omnivore(const Omnivore&);
        
        Item* clone();

        // Instance methods
        void feed(Item*);
};

#endif