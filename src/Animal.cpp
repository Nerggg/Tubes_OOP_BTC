#include "lib/Animal.hpp"

// Static Attribute
map<string, Animal *> Animal::AnimalData;

// ========================================================
// ====================== Animal ==========================
// =================== Constructors =======================
// ========================================================

Animal::Animal() : Item()
{
    this->harvestWeight = 0;
    this->weight = 0;
}

Animal::Animal(
    int id,
    string code,
    string name,
    string type,
    int harvestWeight,
    int price) : Item(id, code, name, type, price)
{
    this->harvestWeight = harvestWeight;
    this->weight = 0;
}

Animal::Animal(const Animal &a)
{
    this->id = a.id;
    this->code = a.code;
    this->name = a.name;
    this->type = a.type;
    this->harvestWeight = a.harvestWeight;
    this->weight = a.weight;
    this->price = a.price;
}

ostream &Animal::printDetails(ostream &out)
{
    out << "ID: " << this->id << endl;
    out << "Animal Code: " << this->code << endl;
    out << "Animal Name: " << this->name << endl;
    out << "Animal Type: " << this->type << endl;
    out << "Animal Weight: " << this->weight << endl;
    out << "Animal Harvest Weight: " << this->harvestWeight << endl;
    out << "Animal Price: " << this->price << endl;
    out << endl;

    return out;
}

ostream &operator<<(ostream &out, Animal *x)
{
    return x->printDetails(out);
}

// ========================================================
// ====================== Animal ==========================
// =================  Static Methods ======================
// ========================================================

map<string, Animal *> Animal::getAnimalData()
{
    return Animal::AnimalData;
};

// ========================================================
// ====================== Animal ==========================
// ===================== Printers =========================
// ========================================================

SlowPrinter Animal::slowPrintDetails(SlowPrinter slowp)
{
    slowp << "ID: " << this->id << endl;
    slowp << "Animal Code: " << this->code << endl;
    slowp << "Animal Name: " << this->name << endl;
    slowp << "Animal Type: " << this->type << endl;
    slowp << "Animal Weight: " << this->weight << endl;
    slowp << "Animal Harvest Weight: " << this->harvestWeight << endl;
    slowp << "Animal Price: " << this->price << endl;
    slowp << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Animal *x)
{
    return x->slowPrintDetails(slowp);
}

// ========================================================
// ====================== Animal ==========================
// ===================== Getters ==========================
// ========================================================

int Animal::getHarvestWeight()
{
    return this->harvestWeight;
}

int Animal::getWeight()
{
    return this->weight;
}

bool Animal::operator==(Animal *a)
{
    return (this->id == a->id) &&
           (this->code == a->code) &&
           (this->name == a->name) &&
           (this->type == a->type) &&
           (this->harvestWeight == a->harvestWeight) &&
           (this->weight == a->weight) &&
           (this->price == a->price);
}

// ========================================================
// ====================== Animal ==========================
// ===================== Setters ==========================
// ========================================================

Animal &Animal::operator+=(int w)
{
    this->weight += w;
    return *this;
}

// ========================================================
// ====================== Animal ==========================
// ================== Type Checkers =======================
// ========================================================

bool Animal::isAnimal()
{
    return true;
}

bool Animal::isPlant()
{
    return false;
}

bool Animal::isProduct()
{
    return false;
}

bool Animal::isBuilding()
{
    return false;
}

// ========================================================
// ===================== Herbivore ========================
// =================== Constructors =======================
// ========================================================

Herbivore::Herbivore(
    int id,
    string code,
    string name,
    string type,
    int harvestWeight,
    int price) : Animal(id, code, name, type, harvestWeight, price)
{
}

Herbivore::Herbivore(const Herbivore &h) : Animal(h)
{
}

Item *Herbivore::clone()
{
    return new Herbivore(*this);
}

// ========================================================
// ===================== Herbivore ========================
// ================= Instance Methods =====================
// ========================================================

void Herbivore::feed(Item *i)
{
    if (i->isAnimal())
    {
        throw wrongFoodException();
    }
    Product *product = (Product *)i;
    this->weight = this->weight + product->getAddedWeight();
    cout << "Herbivore eating..." << endl;
}

// ========================================================
// ===================== Carnivore ========================
// =================== Constructors =======================
// ========================================================

Carnivore::Carnivore(
    int id,
    string code,
    string name,
    string type,
    int harvestWeight,
    int price) : Animal(id, code, name, type, harvestWeight, price)
{
}

Carnivore::Carnivore(const Carnivore &c) : Animal(c)
{
}

Item *Carnivore::clone()
{
    return new Carnivore(*this);
}

// ========================================================
// ===================== Carnivore ========================
// ================= Instance Methods =====================
// ========================================================

void Carnivore::feed(Item *i)
{
    if (i->isPlant())
    {
        throw wrongFoodException();
    }
    Product *product = (Product *)i;
    this->weight = this->weight + product->getAddedWeight();
    cout << "Carnivore eating..." << endl;
}

// ========================================================
// ===================== Omnivore =========================
// =================== Constructors =======================
// ========================================================
Omnivore::Omnivore(
    int id,
    string code,
    string name,
    string type,
    int harvestWeight,
    int price) : Animal(id, code, name, type, harvestWeight, price)
{
}

Omnivore::Omnivore(const Omnivore &o) : Animal(o)
{
}

Item *Omnivore::clone()
{
    return new Omnivore(*this);
}

// ========================================================
// ===================== Omnivore =========================
// ================= Instance Methods =====================
// ========================================================

void Omnivore::feed(Item *i)
{
    Product *product = (Product *)i;
    this->weight = this->weight + product->getAddedWeight();
    cout << "Omnivore eating..." << endl;
}