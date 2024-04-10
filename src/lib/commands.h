#ifndef __COMMANDS_HPP
#define __COMMANDS_HPP

#include <vector>
#include <string>

using namespace std;

// Command macros
#define HELP "HELP"
#define NEXT "NEXT"
#define CETAK_PENYIMPANAN "CETAK_PENYIMPANAN"
#define PUNGUT_PAJAK "PUNGUT_PAJAK"
#define CETAK_LADANG "CETAK_LADANG"
#define CETAK_PETERNAKAN "CETAK_PETERNAKAN"
#define TANAM "TANAM"
#define TERNAK "TERNAK"
#define BANGUN "BANGUN"
#define MAKAN "MAKAN"
#define KASIH_MAKAN "KASIH_MAKAN"
#define BELI "BELI"
#define JUAL "JUAL"
#define PANEN "PANEN"
#define SIMPAN "SIMPAN"
#define TAMBAH_PEMAIN "TAMBAH_PEMAIN"

// Commands list
extern vector<string> PERINTAH_WALIKOTA;
extern vector<string> PERINTAH_PETANI;
extern vector<string> PERINTAH_PETERNAK;

#endif