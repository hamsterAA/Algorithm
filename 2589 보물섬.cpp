/*
https://www.acmicpc.net/problem/2589
백준 2589 보물섬
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101], ans[101][101];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = vis[i][j];
        }
    }
    return;
}

int main(void){
ios::sync_with_stdio(0);
cin.tie(0);
queue<pair<int,int> > Q;
cin>>n;
cin>>m;
string st;

for(int i = 0; i < n; i++) {
    cin>>st;
    for(int j = 0; j < m; j++) {
        if(st[j] == 'W') {
            vis[i][j] = -1;
        }
        else board[i][j] = 'L';
    }
}

int mm = 0;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(board[i][j] == 'L') Q.push({i,j});
        else continue;
        copy();
        ans[i][j] = 1;
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            int nx; int ny;
            for(int dir = 0; dir < 4; dir++){
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(ans[nx][ny]) continue;
            ans[nx][ny] = ans[cur.X][cur.Y]+1;
            Q.push({nx,ny});
            }
        }

        for(int ii = 0; ii < n; ii++) {
            for(int jj = 0; jj < m; jj++) {
                if(mm < ans[ii][jj]) mm = ans[ii][jj];
            }
        }
    }
}

cout<<mm - 1;
}

/*
풀이

지도가 50 * 50으로 매우 작으므로, 모든 칸을 전부 돌면서 그래프 탐색 해준다.
매번 새로운 거리를 구해야하므로, 거리는 매번 초기화시켜준다.
*/