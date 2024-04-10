#include "../lib/Player.hpp"

// ========================================================
// =================== TAMBAH_PEMAIN ======================
// ========================================================

void Walikota::tambahPemain() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Throw error if money is not enough
    if (this->money < 50) {
        sc << BOLD RED << "Uang anda tidak cukup!" << endl;
        sc << "Penambahan pemain membutuhkan 50 gulden." << RESET << endl << endl;

        sc << BOLD CYAN << "Perintah dibatalkan." << endl;
        return;
    }

    // Add player to database
    string type;
    while (true) {
        sc << BOLD GREEN << "Masukkan jenis pemain (Peternak/Petani): " << RESET;
        cin >> type;

        if (type == TYPE_PETANI || type == TYPE_PETERNAK) {
            break;
        }

        sc << BOLD RED << "Jenis pemain tidak valid!" << RESET << endl;
    }

    string name;
    while (true) {
        try {
            sc << BOLD GREEN << "Masukkan nama pemain: " << RESET;
            cin >> name;

            // Check if name has spaces
            if (name.find(' ') != string::npos) {
                throw nameHasSpacesException();
            }

            // Check if name is already taken
            for (const auto& pair : this->getPlayerData()) {
                if (pair.second->getName() == name) {
                    throw nameAlreadyTakenException();
                }
            }

            // Break if name is valid
            break;
        } catch (nameHasSpacesException& e) {
            sc << BOLD RED << "Nama tidak boleh mengandung spasi!" << RESET << endl;
        } catch (nameAlreadyTakenException& e) {
            sc << BOLD RED << "Nama tersebut sudah dipakai!" << RESET << endl;
        }
    }

    // Create player
    if (type == TYPE_PETANI) {
        this->addPlayer(new Petani(name, 0, 0));
    } else {
        this->addPlayer(new Peternak(name, 0, 0));
    }
}
