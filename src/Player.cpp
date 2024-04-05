#include "lib/Player.hpp"

// Static Attributes
map<string, Player*> Player::PlayerData;
int Player::GuldenWinAmount;
int Player::WeightWinAmount;
bool Player::winningPlayerExists = false;

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

void Walikota::hitungPajak() {
    cout << "Walikota hitung pajak" << endl;
}

string Walikota::getPlayerType() {
    return TYPE_WALIKOTA;
}

void Walikota::cetakPenyimpanan() {
    this->inventory.printInventory();
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

void Petani::hitungPajak() {
    cout << "Petani hitung pajak" << endl;
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

void Petani::cetakPenyimpanan() {
    this->inventory.printInventory();
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

void Peternak::hitungPajak() {
    cout << "Peternak hitung pajak" << endl;
}

string Peternak::getPlayerType() {
    return TYPE_PETERNAK;
}

void Peternak::cetakPenyimpanan() {
    this->inventory.printInventory();
}