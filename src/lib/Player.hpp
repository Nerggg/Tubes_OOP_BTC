#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#define TYPE_WALIKOTA "Walikota"
#define TYPE_PETANI "Petani"
#define TYPE_PETERNAK "Peternak"

#include <algorithm>
#include <cmath>
#include <iomanip>

#include "colors.h"
#include "Inventory.hpp"
#include "SlowPrinter.hpp"
#include "commands.h"
#include "Exception.hpp"

class Player
{
    friend class FileManager;
    friend class Game;

    protected:
        // Static variables
        static map<string, Player *> PlayerData;
        static int GuldenWinAmount;
        static int WeightWinAmount;
        static bool winningPlayerExists;
        static bool isSaving;

        // Instance variables
        string name;
        int weight;
        int money;
        Inventory<Item> inventory;

    public:
        // Constructors
        Player(string, int, int);

        // Static methods
        static int getGuldenWinAmount();
        static int getWeightWinAmount();
        static bool playerHasWon();

        static map<string, Player *> getPlayerData()
        {
            return Player::PlayerData;
        }
        static void addPlayer(Player *);

        // Printers
        SlowPrinter slowPrintDetails(SlowPrinter);
        friend SlowPrinter operator<<(SlowPrinter, Player *);

        // Player command methods
        void Turn();
        virtual bool checkCommandValid(string) = 0;
        void executeCommand(string);

        // Player commmands
        // get commands from commands.h
        virtual void help() {};
        virtual void next();
        void cetakPenyimpanan();
        virtual void pungutPajak() {};
        virtual void cetakLadang() {};
        virtual void cetakPeternakan() {};
        virtual void tanam() {};
        virtual void ternak() {};
        virtual void bangun() {};
        void makan();
        virtual void kasihMakan() {};
        virtual void beli() {};
        virtual void jual() {};
        virtual void panen() {};
        virtual void simpan();
        virtual void tambahPemain() {};

        // Getters
        Inventory<Item> getInventory();
        string getName();
        virtual string getPlayerType() = 0;
        static bool getPlayerIsSaving();

        // Setters
        void insertToInventory(Item *);
        virtual void insertToBarn(Animal *, string) {};
        virtual void insertToFarm(Plant *, string) {};
        virtual void incrementAllPlants() {};

        // Instance methods
        bool checkPlayerWinning();
        virtual int hitungPajak() = 0;
        void withdrawMoney(int);
        void depositMoney(int);
};

class Walikota : public Player {
    friend class FileManager;
    protected:
        // Static variables

        // Instance variables

    public:
        // Constructors
        Walikota(string, int, int);

        // Walikota command methods
        bool checkCommandValid(string);

        // Walikota commands
        void help();
        void pungutPajak();
        void bangun();
        void beli();
        void jual();
        void tambahPemain();

        // Getters
        string getPlayerType();

        // Setters

        // Instance methods
        int hitungPajak();
};

class Petani : public Player {
    friend class FileManager;
    protected:
        // Static variables

        // Instance variables
        Inventory<Plant> farm;

    public:
        // Constructors
        Petani(string, int, int);

        // Petani command methods
        bool checkCommandValid(string);

        // Petani commands
        void help();
        void cetakLadang();
        void tanam();
        void beli();
        void jual();
        void panen();

        // Getters
        string getPlayerType();

        // Setters
        void insertToFarm(Plant *, string);
        void incrementAllPlants();

        // Instance methods
        int hitungPajak();
};

class Peternak : public Player {
    friend class FileManager;
    protected:
        // Static variables

        // Instance variables
        Inventory<Animal> barn;

    public:
        // Constructors
        Peternak(string, int, int);

        // Peternak command methods
        bool checkCommandValid(string);

        // Peternak commands
        void help();
        void cetakPeternakan();
        void ternak();
        void kasihMakan();
        void beli();
        void jual();
        void panen();

        // Getters
        string getPlayerType();

        // Setters
        void insertToBarn(Animal *, string);

        // Instance methods
        int hitungPajak();
};

#endif