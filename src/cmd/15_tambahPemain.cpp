#include "../lib/Player.hpp"

// ========================================================
// =================== TAMBAH_PEMAIN ======================
// ========================================================

void Walikota::tambahPemain() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}
