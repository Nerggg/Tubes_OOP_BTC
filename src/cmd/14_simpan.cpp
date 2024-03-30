#include "../lib/Player.hpp"

// ========================================================
// ======================= SIMPAN =========================
// ========================================================

void Player::simpan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}