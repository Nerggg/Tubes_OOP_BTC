#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#define TYPE_WALIKOTA "Walikota"
#define TYPE_PETANI "Petani"
#define TYPE_PETERNAK "Peternak"

#include <algorithm>
#include <cmath>

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

        // Instance variables
        string name;
        int weight;
        int money;
        Inventory inventory;

    public:
        // Constructors
        Player(string, int, int);

        // Static methods
        static int getGuldenWinAmount();
        static int getWeightWinAmount();
        
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
        Inventory getInventory();

        // Setters
        void insertToInventory(Item*);
        virtual void insertToBarn(Item*, string) {};
        virtual void insertToFarm(Item*, string) {};

        // Instance methods
        virtual void hitungPajak() = 0;
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

        // Setters

        // Instance methods
        void hitungPajak();
};

class Petani : public Player {
    protected:
        // Static variables

        // Instance variables
        Farm farm;

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

        // Setters
        void insertToFarm(Item*, string);

        // Instance methods
        void hitungPajak();
};

class Peternak : public Player {
    protected:
        // Static variables

        // Instance variables
        Barn barn;

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

        // Setters
        void insertToBarn(Item*, string);

        // Instance methods
        void hitungPajak();
};

#endif