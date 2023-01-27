/*
https://www.acmicpc.net/problem/2580
백준 2580 스도쿠
*/

#include <iostream>
#include <vector>
using namespace std;
int arr[9][9], vis[9][9], m;
int isused[10], done;
vector<pair<int, int> > V;
bool avail(int x, int y) {
    bool ava = 1;
    for(int i = 0; i < 9; i++) {
        if(arr[x][i] == arr[x][y] && y != i) return 0;
    }
    for(int i = 0; i < 9; i++) {
        if(arr[i][y] == arr[x][y] && x != i) return 0;
    }
    x /= 3;
    y /= 3;
    x *= 3;
    y *= 3;
    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            isused[arr[i][j]]++;
        }
    }
    for(int i = 1; i <= 9; i++) {
        if(isused[i] > 1) ava = 0;
        isused[i] = 0;
    }

    isused[0] = 0;
    return ava;
}
void func(int k) {
    if(done) return;
    if(k == m) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
        done = 1;
        return;
    }
    
    for(int i = 1; i < 10; i++) {
        arr[V[k].first][V[k].second] = i;
        if(!avail(V[k].first, V[k].second)) continue;
        func(k + 1);
    }
    arr[V[k].first][V[k].second] = 0;
}
int main() {
    pair<int, int> VV;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin>>arr[i][j];
            if(!arr[i][j]) {
                m++;
                VV.first = i;
                VV.second = j;
                V.push_back(VV);
            }
        }
    }
    
    func(0);
}
/*
풀이

백트래킹으로 1부터 넣어보고, 안되면 되돌아온다.
pair<int, int> 를 담을 수 있는 vector를 사용하면 쉽게 풀 수 있다.
*/