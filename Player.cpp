#include "headers/Player.hpp"

map<string, Player*> Player::PlayerData;

// ========================================================
// ====================== Player ==========================
// ========================================================
Player::Player(string name, int weight, int money) {
    this->name = name;
    this->weight = weight;
    this->money = money;
    // this->inventory = Inventory<Item>();

}

void Player::insertToInventory(Item* i) {
    this->inventory += i;
}

Inventory Player::getInventory() {
    return this->inventory;
}

// ========================================================
// ===================== Walikota =========================
// ========================================================
Walikota::Walikota(string name, int weight, int money) : Player(name, weight, money) {
}

void Walikota::hitungPajak() {
    cout << "Walikota hitung pajak" << endl;
}

// ========================================================
// ====================== Petani ==========================
// ========================================================
Petani::Petani(string name, int weight, int money) : Player(name, weight, money) {
    // this->farm = Farm<Plant>();
}

void Petani::hitungPajak() {
    cout << "Petani hitung pajak" << endl;
}

// ========================================================
// ===================== Peternak =========================
// ========================================================
Peternak::Peternak(string name, int weight, int money) : Player(name, weight, money) {
    // this->barn = Barn<Animal>();
}

void Peternak::hitungPajak() {
    cout << "Peternak hitung pajak" << endl;
}