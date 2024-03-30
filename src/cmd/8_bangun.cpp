#include "../lib/Player.hpp"
// ========================================================
// ======================= BANGUN =========================
// ========================================================

void Walikota::bangun() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

