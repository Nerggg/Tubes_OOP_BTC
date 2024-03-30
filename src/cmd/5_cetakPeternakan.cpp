#include "../lib/Player.hpp"
// ========================================================
// ================= CETAK_PETERNAKAN =====================
// ========================================================
void Peternak::cetakPeternakan() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << BOLD YELLOW << "Implementation goes here." << RESET << endl << endl;
}

