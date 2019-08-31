#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 1001;
const int MAX_Y = 1001;

using Point = pair<int,int>;
using Rectangle = pair<Point,Point>;  

int imos(const vector<Rectangle> &recs) {
    vector<vector<int> > nums(MAX_X+1, vector<int>(MAX_Y+1, 0));
    for (auto rec : recs) {
        nums[rec.first.first][rec.first.second]++;
        nums[rec.first.first][rec.second.second]--;
        nums[rec.second.first][rec.first.second]--;
        nums[rec.second.first][rec.second.second]++;
    }
    // 横方向への累積和
    for (int x = 0; x < MAX_X; ++x) 
        for (int y = 0; y < MAX_Y; ++y)
            nums[x][y+1] += nums[x][y];
    // 縦方向への累積和
    for (int y = 0; y < MAX_Y; ++y)
        for (int x = 0; x < MAX_X; ++x)
            nums[x+1][y] += nums[x][y];
    int res = 0;
    for (int x = 0; x <= MAX_X; ++x)
        for (int y = 0; y <= MAX_Y; ++y)
            res = max(res, nums[x][y]);
    return res;
}


int main() {
    int N; cin >> N;
    vector<Rectangle> recs(N);
    for (int i = 0; i < N; ++i)
        cin >> recs[i].first.first >> recs[i].first.second >> recs[i].second.first >> recs[i].second.second;
    cout << imos(recs) << endl;
}