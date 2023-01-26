/*
https://www.acmicpc.net/problem/16234
백준 16234 인구 이동
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
#define X first
#define Y second

int board[51][51], n, l, r;
int vis[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int> > Q;
queue<pair<int,int> > P;
bool check = 1;

void MOVE(int sum) {
    while(!P.empty()) {
        pair<int,int> cur = P.front(); P.pop();
        if(vis[cur.X][cur.Y] != 1) continue;
        board[cur.X][cur.Y] = sum;
        check = 1;
                vis[cur.X][cur.Y]= 2;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] == 1) {
                P.push({nx,ny});
            }
        }
    }
}

void BFS() {
    int sum = 0, count = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        if(vis[cur.X][cur.Y]) continue;
        sum += board[cur.X][cur.Y];
        count++;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(abs(board[cur.X][cur.Y] - board[nx][ny]) >= l && abs(board[cur.X][cur.Y] - board[nx][ny]) <= r) {
                Q.push({nx,ny});
                vis[cur.X][cur.Y]= 1;
            }
        }
    }
    if(count) {sum /= count;
    MOVE(sum);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin>>n>>l>>r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>board[i][j];
        }
    }
    int ans = 0;
    while(check){
        check = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j]) continue;
                for(int dir = 0; dir < 4; dir++) {
                    if(i + dx[dir] >= n || i + dx[dir] < 0 || j + dy[dir] >= n || j + dy[dir] < 0) continue;
                    if((abs(board[i][j] - board[i + dx[dir]][j + dy[dir]]) >= l && abs(board[i][j] - board[i + dx[dir]][j + dy[dir]]) <= r)) {
                        Q.push({i + dx[dir], j + dy[dir]});
                        P.push({i + dx[dir], j + dy[dir]});
                        BFS();
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }

        
        if(check) ans++;
    }
        cout<<ans;
}

/*
풀이

n * n의 지역을 전부 순회하면서 인구이동을 마친 후,
인구 이동이 끝나면 다시 n * n의 지역을 bfs로 전부 순회해야 한다.
새롭게 인구이동 하는 지역이 인구이동을 마친 지역과 반응하지 않도록 구현하는 것이 매우 중요하다.

나는 이 과정에서 Floating point exception이 발생했다.
그 외에도 구현량이 많아서 여러가지 실수가 있어 고치기 힘들었다.
골드 5의 문제지만 여태 푼 문제 중 난이도가 매우 높은 편에 속하는 문제였다.
*/