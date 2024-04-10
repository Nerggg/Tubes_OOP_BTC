#include "lib/Player.hpp"

// ========================================================
// ==================== Commands ==========================
// ========================================================

vector<string> PERINTAH_WALIKOTA = {
    HELP,
    NEXT,
    CETAK_PENYIMPANAN,
    PUNGUT_PAJAK,
    BANGUN,
    MAKAN,    
    BELI,
    JUAL,
    SIMPAN,
    TAMBAH_PEMAIN
};

vector<string> PERINTAH_PETANI = {
    HELP,
    NEXT,
    CETAK_PENYIMPANAN,
    CETAK_LADANG,
    TANAM,
    MAKAN,
    BELI,
    JUAL,
    PANEN,
    SIMPAN
};

vector<string> PERINTAH_PETERNAK = {
    HELP,
    NEXT,
    CETAK_PENYIMPANAN,
    CETAK_PETERNAKAN,
    TERNAK,
    MAKAN,
    KASIH_MAKAN,
    BELI,
    JUAL,
    PANEN,
    SIMPAN
};

// ========================================================
// ================= CheckCommandValid ====================
// ========================================================

bool Walikota::checkCommandValid(string command) {
    return find(PERINTAH_WALIKOTA.begin(), PERINTAH_WALIKOTA.end(), command) != PERINTAH_WALIKOTA.end();
}

bool Petani::checkCommandValid(string command) {
    return find(PERINTAH_PETANI.begin(), PERINTAH_PETANI.end(), command) != PERINTAH_PETANI.end();
}

bool Peternak::checkCommandValid(string command) {
    return find(PERINTAH_PETERNAK.begin(), PERINTAH_PETERNAK.end(), command) != PERINTAH_PETERNAK.end();
}

// ========================================================
// =================== ExecuteCommand =====================
// ========================================================

void Player::executeCommand(string command) {
    if      (command == HELP) help();
    else if (command == NEXT) next();
    else if (command == CETAK_PENYIMPANAN) cetakPenyimpanan();
    else if (command == PUNGUT_PAJAK) pungutPajak();
    else if (command == CETAK_LADANG) cetakLadang();
    else if (command == CETAK_PETERNAKAN) cetakPeternakan();
    else if (command == TANAM) tanam();
    else if (command == TERNAK) ternak();
    else if (command == BANGUN) bangun();
    else if (command == MAKAN) makan();
    else if (command == KASIH_MAKAN) kasihMakan();
    else if (command == BELI) beli();
    else if (command == JUAL) jual();
    else if (command == PANEN) panen();
    else if (command == SIMPAN) simpan();
    else if (command == TAMBAH_PEMAIN) tambahPemain();
}

// ========================================================
// ======================== Turn ==========================
// ========================================================

void Player::Turn() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());
 
    // Get player progress percentage
    float weightProgress = (round((this->weight) * 10000 / (float) getWeightWinAmount())) / (float) 100;
    float moneyProgress = (round((this->money) * 10000 / (float) getGuldenWinAmount())) / (float) 100;

    if (!Player::isSaving) {
        // Print starting message
        sc.setMult(sc.getMult() + 10);
        sc << BOLD BRIGHT_CYAN << "Sekarang giliran pemain " << YELLOW << this->name << "!" << RESET << endl; sc.resetMult();
        sc << BOLD MAGENTA << "Berat badan: " << YELLOW << this->weight << " kg (Progress: " << weightProgress << "%)" << RESET << endl;
        sc << BOLD MAGENTA << "Gulden: " << YELLOW << this->money << " (Progress: " << moneyProgress << "%)" << RESET << endl;
        sc << BOLD BRIGHT_CYAN << "Silahkan jalankan perintah " << YELLOW << "'HELP'" << BRIGHT_CYAN << " untuk mendapatkan perintah yang tersedia." << RESET << endl << endl;
    }
    Player::isSaving = false;

    // Start loop for user input
    string command = "";
    while (command != NEXT) {
        // Get user input
        sc << BOLD GREEN << "> " << RESET;
        cin >> command;

        // Validate user input
        try {
            if (!checkCommandValid(command)) throw commandInvalidException();

            // Execute user input
            executeCommand(command);
        } catch (commandInvalidException e) {
            sc << BOLD << RED << "Perintah tidak valid!" << RESET << endl;
            sc << BOLD << RED << "Silahkan jalankan perintah " << YELLOW << "'HELP'" << BOLD << RED << " untuk mendapatkan perintah yang tersedia." << RESET << endl;
        }
        
        // End game if a player has won
        for (const auto& pair : Player::getPlayerData()) {
            if (pair.second->checkPlayerWinning()) {
                sc << BOLD YELLOW << pair.second->name << MAGENTA << " berhasil memenangkan permainan dengan " << YELLOW << pair.second->weight << " kg berat badan" << MAGENTA << " dan " << YELLOW << pair.second->money << " Gulden!" << endl;
                sc << BRIGHT_CYAN << "Permainan berakhir! Terimakasih telah bermain!" << RESET << endl;
                
                // End game
                Player::winningPlayerExists = true;
                return;
            }
        }

        // Return if player is saving
        if (command == SIMPAN) return;

        // Print current money and weight
        if (command != NEXT) {
            sc << BOLD BRIGHT_CYAN<< "Berat badan: " << YELLOW << this->weight << " kg (Progress: " << weightProgress << "%)" << BOLD BRIGHT_CYAN << " | " << "Gulden: " << YELLOW << this->money << " (Progress: " << moneyProgress << "%)" << RESET << endl;
        }
    }
}