#include "../lib/Player.hpp"

// ========================================================
// ======================= TANAM ==========================
// ========================================================

void Petani::tanam() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

