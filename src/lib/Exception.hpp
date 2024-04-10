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

class folderNotFoundException {
    public:
        const char* what() {
            return "Folder tidak ditemukan";
        };
};

#endif