#include "../lib/Player.hpp"

// ========================================================
// ================== CETAK_PENYIMPANAN ===================
// ========================================================

void Player::cetakPenyimpanan()
{
    // Initialize slowprinter
    SlowPrinter &sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW;
    this->inventory.printInventory();
    sc << RESET << endl << endl;
}

