#include "lib/Player.hpp"
#include <cmath>

// Static Attributes
map<string, Player*> Player::PlayerData;
int Player::GuldenWinAmount;
int Player::WeightWinAmount;
bool Player::winningPlayerExists = false;
bool Player::isSaving = false;

// ========================================================
// ====================== Player ==========================
// ========================================================
Player::Player(string name, int weight, int money) {
    this->name = name;
    this->weight = weight;
    this->money = money;
    this->inventory = Inventory<Item>();

}

int Player::getGuldenWinAmount() {
    return Player::GuldenWinAmount;
}

int Player::getWeightWinAmount() {
    return Player::WeightWinAmount;
}

bool Player::playerHasWon() {
    return Player::winningPlayerExists;
}

bool Player::getPlayerIsSaving() {
    return Player::isSaving;
}

void Player::insertToInventory(Item* i) {
    this->inventory += i;
}

Inventory<Item> Player::getInventory() {
    return this->inventory;
}


void Player::addPlayer(Player* p) {
    Player::PlayerData[p->name] = p;
}

SlowPrinter Player::slowPrintDetails(SlowPrinter slowp) {
    slowp << "Name: " << this->name << endl;
    slowp << "Weight: " << this->weight << endl;
    slowp << "Money: " << this->money << endl;
    slowp << "Free Inventory Slots: " << this->inventory.getEmptySlotsCount() << endl;

    return slowp;
}

SlowPrinter operator<<(SlowPrinter slowp, Player* p) {
    return p->slowPrintDetails(slowp);
}

bool Player::checkPlayerWinning() {
    return (this->weight >= Player::WeightWinAmount) && (this->money >= Player::GuldenWinAmount);
}

void Player::withdrawMoney(int amount) {
    int res = this->money - amount;
    
    this->money = max(res, 0);
}

void Player::depositMoney(int amount) {
    this->money += amount;
}

// ========================================================
// ===================== Walikota =========================
// ========================================================
Walikota::Walikota(string name, int weight, int money) : Player(name, weight, money) {
}

int Walikota::hitungPajak() {
    return 0;
}

string Walikota::getPlayerType() {
    return TYPE_WALIKOTA;
}

// ========================================================
// ====================== Petani ==========================
// ========================================================
Petani::Petani(string name, int weight, int money) : Player(name, weight, money) {
    this->farm = Inventory<Plant>(InventoryContainer::FarmRows, InventoryContainer::FarmCols);
}

void Petani::insertToFarm(Plant* i, string slot) {
    this->farm.InsertItemAt(i, slot);
}

int Petani::hitungPajak() {
    float kkp = this->money;
    map<string, Item*>::iterator it;
    map<string, Item*> inv = this->inventory.getAllItems();
    for (it = inv.begin(); it != inv.end(); it++) {
        kkp += it->second->getPrice();
    }
    kkp -= 13;
    float pajak;

    if (kkp <= 6) {
        pajak = kkp * 0.05;
    }
    else if (kkp <= 25) {
        pajak = kkp * 0.15;
    }
    else if (kkp <= 50) {
        pajak = kkp * 0.25;
    }
    else if (kkp <= 500) {
        pajak = kkp * 0.30;
    }
    else {
        pajak = kkp * 0.35;
    }

    if (this->money < pajak) {
        this->money = 0;
    }
    else {
        this->money -= pajak;
    }

    return int(round(pajak));
}

string Petani::getPlayerType() {
    return TYPE_PETANI;
}

void Petani::incrementAllPlants() {
    // Get plants in farm
    map<string, Plant*> plants = this->farm.getAllItems();
    
    // Increment all plants' age
    for (auto const& pair : plants) {
        Plant* plant = pair.second;
        (*plant)++;
    }
}

// ========================================================
// ===================== Peternak =========================
// ========================================================
Peternak::Peternak(string name, int weight, int money) : Player(name, weight, money) {
    this->barn = Inventory<Animal>(InventoryContainer::BarnRows, InventoryContainer::BarnCols);
}

void Peternak::insertToBarn(Animal* i, string slot) {
    this->barn.InsertItemAt(i, slot);
}

int Peternak::hitungPajak() {
    float kkp = this->money;
    map<string, Item*>::iterator it;
    map<string, Item*> inv = this->inventory.getAllItems();
    for (it = inv.begin(); it != inv.end(); it++) {
        kkp += it->second->getPrice();
    }
    kkp -= 11;
    float pajak;

    if (kkp <= 6) {
        pajak = kkp * 0.05;
    }
    else if (kkp <= 25) {
        pajak = kkp * 0.15;
    }
    else if (kkp <= 50) {
        pajak = kkp * 0.25;
    }
    else if (kkp <= 500) {
        pajak = kkp * 0.30;
    }
    else {
        pajak = kkp * 0.35;
    }

    if (this->money < pajak) {
        this->money = 0;
    }
    else {
        this->money -= pajak;
    }

    return int(round(pajak));
}

string Peternak::getPlayerType() {
    return TYPE_PETERNAK;
}