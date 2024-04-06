#include "../lib/Player.hpp"

// ========================================================
// =================== CETAK_LADANG =======================
// ========================================================

void Petani::cetakLadang() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW;
    this->farm.printInventory();
    sc << RESET << endl << endl;
}

