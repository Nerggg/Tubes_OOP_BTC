#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#define TYPE_WALIKOTA "Walikota"
#define TYPE_PETANI "Petani"
#define TYPE_PETERNAK "Peternak"

#include "Inventory.hpp"

class Player {
    protected:
        static map<string, Player*> PlayerData;

        int weight;
        int money;
        Inventory inventory;

    public:
        Player(int, int);

        virtual void hitungPajak() = 0;
};

class Walikota : public Player {
    protected:

    public:
        Walikota(int, int);

        void hitungPajak();
};

class Petani : public Player {
    protected:
        Farm farm;

    public:
        Petani(int, int);

        void hitungPajak();
};

class Peternak : public Player {
    protected:
        Barn barn;

    public:
        Peternak(int, int);
        
        void hitungPajak();
};

#endif