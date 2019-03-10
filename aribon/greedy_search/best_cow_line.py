"""
N文字の文字列Sが与えられ，N文字の文字列Tを作る．
始めは，Tは長さ0の文字列で，
- Sの先頭を1文字削除し，Tの末尾に追加する
- Sの末尾を1文字削除し，Tの末尾に追加する
といった操作ができる．
辞書順比較でできるだけ小さくなるようにTを作れ．

"""

N = int(input())
S = list(input())
T = ""
rev_S = S.copy()
rev_S.reverse()

while(len(S) > 0):
    # print(S)
    # print(rev_S)
    # print(S < rev_S)
    if S < rev_S:
        T += S[0]
        S.pop(0)
        rev_S.pop(-1)

    else:
        T += rev_S[0]
        S.pop(-1)
        rev_S.pop(0)
print(T)
