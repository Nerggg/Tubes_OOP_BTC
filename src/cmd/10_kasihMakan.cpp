#include "../lib/Player.hpp"

// ========================================================
// ===================== KASIH_MAKAN ======================
// ========================================================

void Peternak::kasihMakan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}