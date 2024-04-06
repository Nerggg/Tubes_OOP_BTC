#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#define TYPE_WALIKOTA "Walikota"
#define TYPE_PETANI "Petani"
#define TYPE_PETERNAK "Peternak"

#include <algorithm>
#include <cmath>
#include <iomanip>

#include "Inventory.hpp"
#include "SlowPrinter.hpp"
#include "colors.h"
#include "commands.h"
#include "Exception.hpp"

class Player {
    friend class FileManager;
    protected:
        // Static variables
        static map<string, Player*> PlayerData;
        static int GuldenWinAmount;
        static int WeightWinAmount;
        static bool winningPlayerExists;

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
        
        static map<string, Player*> getPlayerData() {
            return Player::PlayerData;
        }
        static void addPlayer(Player*);

        // Printers
        SlowPrinter slowPrintDetails(SlowPrinter);
        friend SlowPrinter operator<<(SlowPrinter, Player*);
 
        // Player command methods
        void Turn();
        virtual bool checkCommandValid(string) = 0;
        void executeCommand(string); 

        // Player commmands
        // get commands from commands.h
        virtual void help() {};
        virtual void next();
        virtual void cetakPenyimpanan() {};
        virtual void pungutPajak() {};
        virtual void cetakLadang() {};
        virtual void cetakPeternakan() {};
        virtual void tanam() {};
        virtual void ternak() {};
        virtual void bangun() {};
        virtual void makan() {};
        virtual void kasihMakan() {};
        virtual void beli() {};
        virtual void jual() {};
        virtual void panen() {};
        virtual void simpan();
        virtual void tambahPemain() {};
        
        // Getters
        Inventory<Item> getInventory();
        virtual string getPlayerType() = 0;

        // Setters
        void insertToInventory(Item*);
        virtual void insertToBarn(Animal*, string) {};
        virtual void insertToFarm(Plant*, string) {};
        virtual void incrementAllPlants() {};

        // Instance methods
        bool checkPlayerWinning();
        virtual void hitungPajak() = 0;
        void withdrawMoney(int);
        void depositMoney(int);
};

class Walikota : public Player {
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
        void cetakPenyimpanan();
        void pungutPajak();
        void bangun();
        void makan();
        void beli();
        void jual();
        void tambahPemain();
        
        // Getters
        string getPlayerType();

        // Setters

        // Instance methods
        void hitungPajak();
};

class Petani : public Player {
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
        void cetakPenyimpanan();
        void cetakLadang();
        void tanam();
        void makan();
        void beli();
        void jual();
        void panen();

        // Getters
        string getPlayerType();

        // Setters
        void insertToFarm(Plant*, string);
        void incrementAllPlants();

        // Instance methods
        void hitungPajak();
};

class Peternak : public Player {
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
        void cetakPenyimpanan();
        void cetakPeternakan();
        void ternak();
        void makan();
        void kasihMakan();
        void beli();
        void jual();
        void panen();

        // Getters
        string getPlayerType();

        // Setters
        void insertToBarn(Animal*, string);

        // Instance methods
        void hitungPajak();
};

#endif