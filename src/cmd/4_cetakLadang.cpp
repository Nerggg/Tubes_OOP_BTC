#include "../lib/Player.hpp"
// ========================================================
// =================== CETAK_LADANG =======================
// ========================================================

void Petani::cetakLadang() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

