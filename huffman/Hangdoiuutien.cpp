#include<bits/stdc++.h>
#include "Node.cpp"


#ifndef Hangdoiuutien
#define Hangdoiuutien

using namespace std;

class HangDoiUuTien {
private:
    Node *nodes[MAXCHAR];
    int size;

public:
    HangDoiUuTien() : size(0) {}

    bool isempty() {
        return size == 0;
    }

    int getsize(){
        return size;
    }

    void push(Node* node) {
        nodes[size++] = node;
        int i = size - 1;
        while (i > 0 && nodes[(i - 1) / 2]->tansuat > nodes[i]->tansuat) {
            swap(nodes[i], nodes[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    Node* pop() {
        if (isempty()) return nullptr;
        Node* a = nodes[0];
        nodes[0] = nodes[--size];
        int i = 0;
        while (2 * i + 1 < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < size && nodes[left]->tansuat < nodes[smallest]->tansuat) smallest = left;
            if (right < size && nodes[right]->tansuat < nodes[smallest]->tansuat) smallest = right;

            if (smallest == i) break;

            swap(nodes[i], nodes[smallest]);
            i = smallest;
        }
        return a;
    }
};

#endif
