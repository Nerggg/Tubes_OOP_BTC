#include "../lib/Player.hpp"
// ========================================================
// ======================== HELP ==========================
// ========================================================

void Walikota::help() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD MAGENTA << "Perintah yang tersedia: " << RESET << endl;
    sc.setMult(0);
    for (string command : PERINTAH_WALIKOTA) {
        sc << BOLD YELLOW << "- " << command << RESET << endl;
    }
    sc.resetMult();
    sc << endl;
}

void Petani::help() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD MAGENTA << "Perintah yang tersedia: " << RESET << endl;
    sc.setMult(0);
    for (string command : PERINTAH_PETANI) {
        sc << BOLD YELLOW << "- " << command << RESET << endl;
    }
    sc.resetMult();
    sc << endl;
}

void Peternak::help() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD MAGENTA << "Perintah yang tersedia: " << RESET << endl;
    sc.setMult(0);
    for (string command : PERINTAH_PETERNAK) {
        sc << BOLD YELLOW << "- " << command << RESET << endl;
    }
    sc.resetMult();
    sc << endl;
}