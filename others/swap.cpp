#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int tmp; tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 10, b = 20;
    cout << a << " " << b;
    swap(&a, &b);
    cout << a << " " << b;
}