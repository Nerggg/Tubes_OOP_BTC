#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

using namespace std;

class vectorOutOfRangeException {
    public:
        const char* what() {
            return "Indeks invalid";
        };
};

class moneyNotEnoughException {
    public:
        const char* what() {
            return "Uang Anda tidak mencukupi";
        };
};

class storageNotEnoughException {
    public:
        const char* what() {
            return "Kapasitas Anda tidak mencukupi";
        };
};

class invalidSlotException {
    public:
        const char* what() {
            return "Slot yang Anda masukkan tidak valid";
        };
};

class storeStockNotEnoughException {
    public:
        const char* what() {
            return "Stok barang tersebut tidak mencukupi";
        };
};

class commandInvalidException {
    public:
        const char* what() {
            return "Perintah invalid! Tolong masukkan perintah yang benar.";
        };
};

class wrongFoodException {
public:
    const char *what() {
        return "Jangan kasih makan itu dong, gabisa!";
    };
};

class fileNotFoundException {
    public:
        const char* what() {
            return "File tidak ditemukan";
        };
};

class folderNotFoundException {
    public:
        const char* what() {
            return "Folder tidak ditemukan";
        };
};

class nameHasSpacesException {
    public:
        const char* what() {
            return "Nama tidak boleh mengandung spasi";
        };
};

class nameAlreadyTakenException {
    public:
        const char* what() {
            return "Nama sudah digunakan";
        };
};

#endif