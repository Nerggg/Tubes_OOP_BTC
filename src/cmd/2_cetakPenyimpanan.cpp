#include "../lib/Player.hpp"

// ========================================================
// ================== CETAK_PENYIMPANAN ===================
// ========================================================

void Walikota::cetakPenyimpanan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW;
    this->inventory.printInventory();
    sc << RESET << endl << endl;
}

void Petani::cetakPenyimpanan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW;
    this->inventory.printInventory();
    sc << RESET << endl << endl;
}

void Peternak::cetakPenyimpanan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW;
    this->inventory.printInventory();
    sc << RESET << endl << endl;
}

