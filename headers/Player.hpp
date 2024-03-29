#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#define TYPE_WALIKOTA "Walikota"
#define TYPE_PETANI "Petani"
#define TYPE_PETERNAK "Peternak"

#include "Inventory.hpp"

class Player {
    friend class FileManager;
    protected:
        static map<string, Player*> PlayerData;

        string name;
        int weight;
        int money;
        Inventory inventory;

    public:
        Player(string, int, int);

        virtual void hitungPajak() = 0;
        void insertToInventory(Item*);
        Inventory getInventory();

        static map<string, Player*> getPlayerData() {
            return Player::PlayerData;
        }
};

class Walikota : public Player {
    protected:

    public:
        Walikota(string, int, int);

        void hitungPajak();
};

class Petani : public Player {
    protected:
        Farm farm;

    public:
        Petani(string, int, int);

        void hitungPajak();
};

class Peternak : public Player {
    protected:
        Barn barn;

    public:
        Peternak(string, int, int);
        
        void hitungPajak();
};

#endif