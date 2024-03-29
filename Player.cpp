#include "headers/Player.hpp"

map<string, Player*> Player::PlayerData;

// ========================================================
// ====================== Player ==========================
// ========================================================
Player::Player(int weight, int money) {
    this->weight = weight;
    this->money = money;
    // this->inventory = Inventory<Item>();

}

// ========================================================
// ===================== Walikota =========================
// ========================================================
Walikota::Walikota(int weight, int money) : Player(weight, money) {
}

void Walikota::hitungPajak() {
    cout << "Walikota hitung pajak" << endl;
}

// ========================================================
// ====================== Petani ==========================
// ========================================================
Petani::Petani(int weight, int money) : Player(weight, money) {
    // this->farm = Farm<Plant>();
}

void Petani::hitungPajak() {
    cout << "Petani hitung pajak" << endl;
}

// ========================================================
// ===================== Peternak =========================
// ========================================================
Peternak::Peternak(int weight, int money) : Player(weight, money) {
    // this->barn = Barn<Animal>();
}

void Peternak::hitungPajak() {
    cout << "Peternak hitung pajak" << endl;
}