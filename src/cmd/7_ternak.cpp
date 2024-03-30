#include "../lib/Player.hpp"
// ========================================================
// ======================= TERNAK =========================
// ========================================================

void Peternak::ternak() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

