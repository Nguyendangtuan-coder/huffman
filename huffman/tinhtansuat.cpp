#include<bits/stdc++.h>

using namespace std;

#ifndef Tinhtansuat
#define Tinhtansuat

void tinhtansuat(const char* chuoi, int tansuat[MAXCHAR]) {
    for (int i = 0; i < MAXCHAR; i++) tansuat[i] = 0;
    for (int i = 0; chuoi[i] != '\0'; i++) tansuat[(int)chuoi[i]]++;
}

#endif