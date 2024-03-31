#include "lib/Player.hpp"

// Static Attributes
map<string, Player*> Player::PlayerData;
int Player::GuldenWinAmount;
int Player::WeightWinAmount;

// ========================================================
// ====================== Player ==========================
// ========================================================
Player::Player(string name, int weight, int money) {
    this->name = name;
    this->weight = weight;
    this->money = money;
    // this->inventory = Inventory<Item>();

}

int Player::getGuldenWinAmount() {
    return Player::GuldenWinAmount;
}

int Player::getWeightWinAmount() {
    return Player::WeightWinAmount;
}

void Player::insertToInventory(Item* i) {
    this->inventory += i;
}

Inventory Player::getInventory() {
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

// ========================================================
// ====================== Petani ==========================
// ========================================================
Petani::Petani(string name, int weight, int money) : Player(name, weight, money) {
    // this->farm = Farm<Plant>();
}

void Petani::insertToFarm(Item* i, string slot) {
    this->farm.InsertItemAt(i, slot);
}

void Petani::hitungPajak() {
    cout << "Petani hitung pajak" << endl;
}

string Petani::getPlayerType() {
    return TYPE_PETANI;
}

// ========================================================
// ===================== Peternak =========================
// ========================================================
Peternak::Peternak(string name, int weight, int money) : Player(name, weight, money) {
    // this->barn = Barn<Animal>();
}

void Peternak::insertToBarn(Item* i, string slot) {
    this->barn.InsertItemAt(i, slot);
}

void Peternak::hitungPajak() {
    cout << "Peternak hitung pajak" << endl;
}

string Peternak::getPlayerType() {
    return TYPE_PETERNAK;
}