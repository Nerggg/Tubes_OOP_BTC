#include "../lib/Player.hpp"

// ========================================================
// ======================== NEXT ==========================
// ========================================================

void Player::next() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc.setMult(sc.getMult() + 5);
    sc << BOLD MAGENTA << "Pemain " << YELLOW << this->name << MAGENTA << " mengakhiri gilirannya." << endl;
    sc << BOLD MAGENTA << "Giliran dilanjutkan ke pemain berikutnya." << RESET << endl << endl;
    sc.resetDelay();
}

