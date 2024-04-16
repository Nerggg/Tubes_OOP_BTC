# Tugas Besar Pemrograman Berorientasi Objek IF2210

## Kelola Kerajaan Bersama Labpro

## Table of Contents

- [Table of Contents](#table-of-contents)
- [General Information](#general-information)
- [Contributor](#contributor)
- [Structure](#structure)
- [Dependencies](#dependencies)
- [How to Use](#how-to-use)

## General Information

Bondowoso kini sudah menikah dengan Roro setelah berhasil menjadi kampiun dalam kompetisi membangun 1000 candi. Akan tetapi, hingga kini Roro belum bahagia setelah menikah dengan Bondowoso meskipun Bondowoso sudah memberikannya sebuah griya tawang yang elok. Dia kerap kali terbayang-bayang bagaimana seronoknya mengelola kerajaan seperti zaman dahulu. 

Melihat hal ini, terbesit pikiran di hati Bondowoso untuk mengijinkan Roro mengelola kerajaannya. Akan tetapi, Bondowoso belum tahu apakah Roro sudah cukup berkapabilitas dalam mengelola kerajaannya, yang tentunya karakteristik masyarakat pada kerajaannya berbeda dengan kerajaan Roro dahulu. Oleh karena itu, Bondowoso ingin membuat terlebih dahulu sebuah gim simulasi sederhana mengelola kerajaan yang sudah disesuaikan dengan kondisi masyarakatnya.

## Contributor

| Name                    | NIM      |
| ----------------------- | -------- |
| Rizqika Mulia Pratama | 13522126 |
| Owen Tobias Sinurat | 13522131 |
| Muhammad Fatihul Irhab | 13522143 |
| Ikhwan Al Hakim         | 13522147 |
| Muhammad Rasheed Qais Tandjung | 13522158 |

## Structure

```
├── config
│   ├── animal.txt
│   ├── misc.txt
│   ├── plant.txt
│   ├── product.txt
│   └── recipe.txt
├── doc
│   └── IF2210_TB1_Laporan_BTC.pdf
├── Makefile
├── readme.md
├── save
│   ├── ahuy.txt
│   ├── new_state.txt
│   └── state.txt
├── src
│   ├── Animal.cpp
│   ├── cmd
│   │   ├── 0_help.cpp
│   │   ├── 10_kasihMakan.cpp
│   │   ├── 11_beli.cpp
│   │   ├── 12_jual.cpp
│   │   ├── 13_panen.cpp
│   │   ├── 14_simpan.cpp
│   │   ├── 15_tambahPemain.cpp
│   │   ├── 1_next.cpp
│   │   ├── 2_cetakPenyimpanan.cpp
│   │   ├── 3_pungutPajak.cpp
│   │   ├── 4_cetakLadang.cpp
│   │   ├── 5_cetakPeternakan.cpp
│   │   ├── 6_tanam.cpp
│   │   ├── 7_ternak.cpp
│   │   ├── 8_bangun.cpp
│   │   └── 9_makan.cpp
│   ├── FileManager.cpp
│   ├── Game.cpp
│   ├── Inventory.cpp
│   ├── Item.cpp
│   ├── lib
│   │   ├── Animal.hpp
│   │   ├── colors.h
│   │   ├── commands.h
│   │   ├── Exception.hpp
│   │   ├── Game.hpp
│   │   ├── Inventory.hpp
│   │   ├── Item.hpp
│   │   ├── Plant.hpp
│   │   ├── Player.hpp
│   │   ├── SlowPrinter.hpp
│   │   └── Store.hpp
│   ├── main.cpp
│   ├── Plant.cpp
│   ├── PlayerCommands.cpp
│   ├── Player.cpp
│   ├── SlowPrinter.cpp
│   └── Store.cpp
└── test
    ├── test
    ├── test.cpp
    ├── test_exists.cpp
    ├── testinv.cpp
    └── test_template.cpp
```

## Dependencies

Compiler C++ seperti g++

## How to Use

1. Clone repository ini
   ```
   git clone https://github.com/Nerggg/Tubes_OOP_BTC
   ```
2. Lakukan navigasi ke direktori `Tubes_OOP_BTC`
   ```
   cd Tubes_OOP_BTC
   ```
3. Compile program
   ```
   make
   ```
4. Jalankan program
   ```
   make run
   ```
