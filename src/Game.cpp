#include "lib/Game.hpp"

Game::Game() {    
    // Initialize game data
    FileManager::readPlantData();
    FileManager::readAnimalData();
    FileManager::readProductData();
    FileManager::readBuildingData();
    FileManager::readMiscData();

    // Initialize game
    this->Initialize();

    // Start game loop
    this->Start();
}

void Game::Start() {
    while (!Player::playerHasWon()) {
        for (const auto& pair : Player::PlayerData) {
            // Get next player
            Player* player = pair.second;

            do {
                // Run the player's turn method
                player->Turn();

                // Break if a player has won
                if (Player::playerHasWon()) break;

                // Save player data if player runs save command
                if (Player::getPlayerIsSaving()) FileManager::writePlayerData();
            } while (Player::getPlayerIsSaving());

            // Increment all plant ages
            for (const auto& pair : Player::PlayerData) {
                Player* player = pair.second;
                player->incrementAllPlants();
            }
        }
    }
}

void Game::Initialize() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Print welcome message
    sc << BOLD MAGENTA << "Selamat datang di "; sc.setMult(0); sc << REVERSE_VIDEO YELLOW << "Harvest " << RED CROSSED_OUT << "Bitcoin" << RESET BOLD REVERSE_VIDEO YELLOW << " Gulden!" << RESET << endl << endl; sc.resetMult();

    sc << BOLD MAGENTA << "Misi anda: " << GREEN << "Jadi kaya dan jadi gemuk!" << RESET << endl; sc.setMult(0);
    sc << BOLD BRIGHT_CYAN << "Dapatkan " << YELLOW << Player::getGuldenWinAmount() << " Gulden" << BRIGHT_CYAN << " dan " << YELLOW << Player::getWeightWinAmount() << " kg berat badan"; sc.resetMult(); sc << BRIGHT_CYAN << " untuk memenangkan permainan." << endl << endl;

    // Choose player lineup
    sc << BOLD BRIGHT_CYAN << "Pilihlah setup pemain yang ingin anda pakai: " << RESET << endl;
    sc << BOLD YELLOW << "1. Setup pemain default: 3 pemain" << RESET << endl;
    sc << BOLD YELLOW << "2. Muat setup pemain dari file" << RESET << endl << endl;

    // Validate choice
    bool valid = false;
    string choice;
    while (!valid) {
        sc << BOLD GREEN << "Pilihan anda: " << RESET;
        cin >> choice;

        try {
            if (choice != "1" && choice != "2") throw commandInvalidException();
            valid = true;
        } catch (commandInvalidException e) {
            sc << BOLD << RED << "Pilihan tidak valid! Silakan pilih 1 atau 2." << RESET << endl;
        }
    }
    sc << endl;

    // Load from save file
    string path;
    if (choice == "2") {
        sc << BOLD BRIGHT_CYAN << "Silahkan masukkan lokasi file simpanan anda. (Contoh: './save/bondowoso/state.txt')" << RESET << endl;

        while (true) {
            sc << BOLD GREEN << "Lokasi file: " << RESET;
            cin >> path;

            // Check if file exists
            try {
                if (!filesystem::exists(path)) throw fileNotFoundException();

                break; 
            } catch (fileNotFoundException e) {
                sc << BOLD RED << "File tidak ditemukan!" << endl;
                sc << "Silahkan masukkan ulang lokasi penyimpanan file." << RESET << endl;
            }
        }
    }
    sc << endl;

    // Load default lineup
    sc << BOLD MAGENTA << "Memuat setup pemain..." << RESET << endl;
    sc.setMult(3);
    sc << BOLD BRIGHT_CYAN << ">> ";
    sc.setDelay(100); sc << BOLD BG_YELLOW << "                                        " << RESET << endl; sc.resetDelay();
    sc.resetMult();
    if (choice == "1") {
        // Load default lineup
        Player* p1 = new Petani("Petani1", 40, 50);
        Player* p2 = new Peternak("Peternak1", 40, 50);
        Player* p3 = new Walikota("Walikota", 40, 50);

        // Insert players to PlayerData
        Player::addPlayer(p1);
        Player::addPlayer(p2);
        Player::addPlayer(p3);
    } else {
        // Load lineup from file
        FileManager::readPlayerData(path);
    }
    sc << endl;
    sc << BOLD MAGENTA << "Setup pemain berhasil dimuat!" << RESET << endl;
    sc << BOLD MAGENTA << "Memulai permainan!" << RESET << endl << endl;
}