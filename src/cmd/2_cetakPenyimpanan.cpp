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
    int lineLength = this->inventory.getInvRows() * 6 + 3;
    string title = " Penyimpanan ";
    title = string((lineLength - title.length()) / 2 - 4, '=') + title + string((lineLength - title.length() + 1) / 2, '=');

    cout << "    ";
    sc << title << endl;

    this->inventory.printInventory();
    sc << RESET << endl
       << endl;
}
