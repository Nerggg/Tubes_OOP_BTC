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

Player::~Player(){}

int Player::getGuldenWinAmount() {
    return Player::GuldenWinAmount;
}

int Player::getWeightWinAmount() {
    return Player::WeightWinAmount;
}

bool Player::playerHasWon() {
    return Player::winningPlayerExists;
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

Inventory<Item> Player::getInventory() {
    return this->inventory;
}

void Player::insertToInventory(Item* i) {
    this->inventory += i;
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

bool Walikota::checkCommandValid(string command) {
    return false;
}

void Walikota::next() {
    cout << "Walikota next" << endl;
}

void Walikota::help(){
    cout << "Walikota help" << endl;
}

void Walikota::cetakPenyimpanan() {
    this->inventory.printInventory();
}

void Walikota::pungutPajak() {
    cout << "Walikota pungut pajak" << endl;
}

void Walikota::cetakLadang() {}

void Walikota::cetakPeternakan() {}

void Walikota::tanam() {}

void Walikota::ternak() {}

void Walikota::bangun() {
    cout << "Walikota bangun" << endl;
}

void Walikota::makan() {
    cout << "Walikota makan" << endl;
}

void Walikota::kasihMakan() {}

void Walikota::beli() {
    cout << "Walikota beli" << endl;
}

void Walikota::jual() {
    cout << "Walikota jual" << endl;
}

void Walikota::panen() {}

void Walikota::simpan() {}

void Walikota::tambahPemain() {
    cout << "Walikota tambah pemain" << endl;
}

string Walikota::getPlayerType() {
    return TYPE_WALIKOTA;
}


void Walikota::hitungPajak() {
    cout << "Walikota hitung pajak" << endl;
}

// ========================================================
// ====================== Petani ==========================
// ========================================================
Petani::Petani(string name, int weight, int money) : Player(name, weight, money) {
    this->farm = Inventory<Plant>(InventoryContainer::FarmRows, InventoryContainer::FarmCols);
}

Petani::~Petani() {}

bool Petani::checkCommandValid(string command) {
    return false;
}

void Petani::help() {
    cout << "Petani help" << endl;
}

void Petani::cetakPenyimpanan() {
    this->inventory.printInventory();
}

void Petani::cetakLadang() {
    this->farm.printInventory();
}

void Petani::tanam() {
    cout << "Petani tanam" << endl;
}

void Petani::makan() {
    cout << "Petani makan" << endl;
}

void Petani::beli() {
    cout << "Petani beli" << endl;
}

void Petani::jual() {
    cout << "Petani jual" << endl;
}

void Petani::panen() {
    cout << "Petani panen" << endl;
}

string Petani::getPlayerType() {
    return TYPE_PETANI;
}

void Petani::insertToFarm(Plant* i, string slot) {
    this->farm.InsertItemAt(i, slot);
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

void Petani::hitungPajak() {
    cout << "Petani hitung pajak" << endl;
}


// ========================================================
// ===================== Peternak =========================
// ========================================================
Peternak::Peternak(string name, int weight, int money) : Player(name, weight, money) {
    this->barn = Inventory<Animal>(InventoryContainer::BarnRows, InventoryContainer::BarnCols);
}

Peternak::~Peternak() {}

bool Peternak::checkCommandValid(string command) {
    return false;
}

void Peternak::help() {
    cout << "Peternak help" << endl;
}

void Peternak::cetakPenyimpanan() {
    this->inventory.printInventory();
}

void Peternak::cetakPeternakan() {
    this->barn.printInventory();
}

void Peternak::ternak() {
    cout << "Peternak ternak" << endl;
}

void Peternak::makan() {
    cout << "Peternak makan" << endl;
}

void Peternak::kasihMakan() {
    cout << "Peternak kasih makan" << endl;
}

void Peternak::beli() {
    cout << "Peternak beli" << endl;
}

void Peternak::jual() {
    cout << "Peternak jual" << endl;
}

void Peternak::panen() {
    cout << "Peternak panen" << endl;
}

string Peternak::getPlayerType() {
    return TYPE_PETERNAK;
}

void Peternak::insertToBarn(Animal* i, string slot) {
    this->barn.InsertItemAt(i, slot);
}

void Peternak::hitungPajak() {
    cout << "Peternak hitung pajak" << endl;
}