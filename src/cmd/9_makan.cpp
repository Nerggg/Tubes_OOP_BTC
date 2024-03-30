#include "../lib/Player.hpp"

// ========================================================
// ======================= MAKAN ==========================
// ========================================================

void Walikota::makan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

void Petani::makan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

void Peternak::makan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

