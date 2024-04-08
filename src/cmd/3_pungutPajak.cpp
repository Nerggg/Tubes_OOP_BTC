#include "../lib/Player.hpp"

// ========================================================
// ==================== PUNGUT_PAJAK ======================
// ========================================================

void Walikota::pungutPajak() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    sc << "Cring cring cring...\nPajak sudah dipungut!\n" << endl;
}

