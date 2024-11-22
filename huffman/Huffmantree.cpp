#include<bits/stdc++.h>
#include "Node.cpp"
#include "Hangdoiuutien.cpp"


#ifndef Huffmantree
#define Huffmantree

using namespace std;

class HuffmanTree {
private:
    Node *goc;
    char makytu[MAXCHAR][MAXCHAR];
    int chieudaima[MAXCHAR];

    void ganmakytu(Node *root, char *ma, int chieudai) {
        if (!root) return;

        if (!root->trai && !root->phai) {
            ma[chieudai] = '\0';
            chieudaima[(int)root->kytu] = chieudai;
            for (int i = 0; i < chieudai; i++) {
                makytu[(int)root->kytu][i] = ma[i];
            }
            return;
        }

        ma[chieudai] = '0';
        ganmakytu(root->trai, ma, chieudai + 1);

        ma[chieudai] = '1';
        ganmakytu(root->phai, ma, chieudai + 1);
    }

public:
    HuffmanTree(int tansuatkytu[MAXCHAR]) {
        HangDoiUuTien hangdoi;

        for (int i = 0; i < MAXCHAR; i++) {
            if (tansuatkytu[i] > 0) {
                hangdoi.push(new Node((char)i, tansuatkytu[i]));
            }
        }

        while (hangdoi.getsize() > 1) {
            Node* trai = hangdoi.pop();
            Node* phai = hangdoi.pop();

            Node* tonghop = new Node('\0', trai->tansuat + phai->tansuat);
            tonghop->trai = trai;
            tonghop->phai = phai;

            hangdoi.push(tonghop);
        }

        goc = hangdoi.pop();

        char maTam[MAXCHAR];
        ganmakytu(goc, maTam, 0);
    }

    void mahoa(const char* chuoi, char* ketqua) {
        int index = 0;
        for (int i = 0; chuoi[i] != '\0'; i++) {
            int kyTu = (int)chuoi[i];
            for (int j = 0; j < chieudaima[kyTu]; j++) {
                ketqua[index++] = makytu[kyTu][j];
            }
        }
        ketqua[index] = '\0';
    }

    void giaima(const char* chuoimahoa, char* ketqua) {
        int index = 0;
        Node *hienTai = goc;
        for (int i = 0; chuoimahoa[i] != '\0'; i++) {
            hienTai = (chuoimahoa[i] == '0') ? hienTai->trai : hienTai->phai;

            if (!hienTai->trai && !hienTai->phai) {
                ketqua[index++] = hienTai->kytu;
                hienTai = goc;
            }
        }
        ketqua[index] = '\0';
    }

    ~HuffmanTree() {
        xoaCay(goc);
    }

private:
    void xoaCay(Node *node) {
        if (node) {
            xoaCay(node->trai);
            xoaCay(node->phai);
            delete node;
        }
    }
};
#endif