/*
N文字の文字列Sが与えられ，N文字の文字列Tを作る．
始めは，Tは長さ0の文字列で，
1. Sの先頭を1文字削除し，Tの末尾に追加する
2. Sの末尾を1文字削除し，Tの末尾に追加する
といった操作ができる．
辞書順比較でできるだけ小さくなるようにTを作れ．
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    char S[N]; for (int i=0; i<N; ++i) cin >> S[i];
    int a=0, b=N-1;

    while (a<=b) {
        bool left = false;
        for (int i=0; a+i<=b; ++i) {
            if (S[a+i] < S[b-i]) {
                left = true;
                break;
            }
            else if (S[a+i] > S[b-i]) {
                left = false;
                break;
            }
        }
        if (left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
}