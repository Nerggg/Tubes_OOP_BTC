#include "../lib/Player.hpp"

// ========================================================
// ==================== PUNGUT_PAJAK ======================
// ========================================================

void Walikota::pungutPajak() {
    // Initialize slowprinter
    SlowPrinter& sc = *(SlowPrinter::getSlowPrinter());

    // Run command
    vector<pair<string, int>> pajakPlayer;
    map<string, Player*> dataPlayer = Player::getPlayerData();
    map<string, Player*>::iterator it;

    int profit = 0, pajakTemp;
    for (it = dataPlayer.begin(); it != dataPlayer.end(); it++) {
        if (it->second->getPlayerType() == TYPE_WALIKOTA) {
            continue;
        }
        pajakTemp = it->second->hitungPajak();
        pajakPlayer.push_back(make_pair(it->first, pajakTemp));
        this->money += pajakTemp;
        profit += pajakTemp;
    }

    auto comparator = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    };

    sort(pajakPlayer.begin(), pajakPlayer.end(), comparator);

    sc << "Cring cring cring...\nPajak sudah dipungut!\n" << endl;
    sc << "Berikut adalah detil dari pemungutan pajak:" << endl;
    
    for (int i = 0; i < int(pajakPlayer.size()); i++) {
        sc << i+1 << ". " << pajakPlayer.at(i).first << " - " << Player::getPlayerData()[pajakPlayer.at(i).first]->getPlayerType() << ": " << pajakPlayer.at(i).second << " gulden" << endl;
    }

    sc << "Negara mendapatkan pemasukan sebesar " << profit << " gulden." << endl;
    sc << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

