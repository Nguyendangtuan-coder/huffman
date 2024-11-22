#include<bits/stdc++.h>
#ifndef nodee
#define nodee

using namespace std;

struct Node {
    char kytu;
    int tansuat;
    Node* trai;
    Node* phai;

    Node(char kyTu = '\0', int tanSuat = 0) {
        kytu = kyTu;
        tansuat = tanSuat;
        trai = nullptr;
        phai = nullptr;
    }
};

#endif
