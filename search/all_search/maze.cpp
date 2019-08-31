// Tasks:
//     大きさN*Mの迷路が与えられる．
//     迷路は通路と壁からできていて，1ターンで隣接する上下左右4マスの通路に移動できる．
//     スタートからゴールまで移動するのに必要な最小のターン数を求めよ．

// Solution:
//     幅優先探索．


// Sample input:
// 10 10
// #S######.#
// ......#..#
// .#.##.##.#
// .#........
// ##.##.####
// ....#....#
// .#######.#
// ....#.....
// .####.###.
// ....#...G#

// expected output:
// 22

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000;
typedef pair<int, int> P;

#define MAX_N INF
#define MAX_M INF

char maze[MAX_N][MAX_M];
int N, M;
int sx, sy, gx, gy;

int d[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        P p = que.front(); que.pop();
        if (p.first == gx && p.second == gy) break;
        for (int i=0; i<4; ++i) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#' && d[nx][ny]==INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            char a;
            cin >> a;
            if (a=='S') {
                sx = i, sy = j;
            }
            if (a=='G') {
                gx = i, gy = j;
            }
            maze[i][j] = a;
        }
    }
    int res = bfs();
    cout << res << endl;
}