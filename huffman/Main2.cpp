#include<bits/stdc++.h>
#include "Huffmantree.cpp"
#include "tinhtansuat.cpp"

#ifndef Main
#define Main

int main() {
    const char* chuoi = "Toi co ma huffman";

    char chuoimahoa[1024];
    char chuoigiaima[1024];

    int tanSuatKyTu[MAXCHAR];
    tinhtansuat(chuoi, tanSuatKyTu);

    HuffmanTree huffman(tanSuatKyTu);

    huffman.mahoa(chuoi, chuoimahoa);
    cout << "Chuoi sau khi ma hoa: " << chuoimahoa << endl;

    huffman.giaima(chuoimahoa, chuoigiaima);
    cout << "Chuoi sau khi giai ma: " << chuoigiaima << endl;

    return 0;
}

#endif