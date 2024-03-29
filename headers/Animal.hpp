#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP

#include "Item.hpp"

// const string TYPE_HERBIVORE = "HERBIVORE";
// const string TYPE_CARNIVORE = "CARNIVORE";
// const string TYPE_OMNIVORE = "OMNIVORE";

#define TYPE_HERBIVORE "HERBIVORE"
#define TYPE_CARNIVORE "CARNIVORE"
#define TYPE_OMNIVORE "OMNIVORE"

class Animal : public Item {
    friend class FileManager;

    protected:
        static map<string, Animal*> AnimalData;

        int harvestWeight;
        int weight;

    public:
        Animal();
        Animal(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price, 
            string itemType
        );
        Animal(const Animal&);

        static map<string, Animal*> getAnimalData() {
            return Animal::AnimalData;
        
        };

        ostream& printDetails(ostream&);
        friend ostream& operator<<(ostream&, Animal*);

        SlowPrinter slowPrintDetails(SlowPrinter);
        friend SlowPrinter operator<<(SlowPrinter, Animal*);

        virtual void feed(Item*) = 0;
};

class Herbivore : public Animal {
    public:
        Herbivore(
            int id, 
            string code,
            string name, 
            string type, 
            int harvestWeight, 
            int price, 
            string itemType
        );
        Herbivore(const Herbivore&);
        Item* clone();
        
        void feed(Item*);
};

class Carnivore : public Animal {
    public:
        Carnivore(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price, 
            string itemType
        );
        Carnivore(const Carnivore&);
        Item* clone();
        
        void feed(Item*);
};

class Omnivore : public Animal {
    public:
        Omnivore(
            int id, 
            string code, 
            string name, 
            string type, 
            int harvestWeight, 
            int price, 
            string itemType
        );
        Omnivore(const Omnivore&);
        Item* clone();

        void feed(Item*);
};

#endif