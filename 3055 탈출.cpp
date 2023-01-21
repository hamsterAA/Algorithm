/*
https://www.acmicpc.net/problem/3055
백준 3055 탈출
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string s;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r,c;
int arr[51][51];
int vis[51][51];
int vis2[51][51];
queue<pair<int,int> > Q;
queue<pair<int,int> > P;
queue<pair<int,int> > S;
//D = 9, X = 4, . = 0, * = 1

void DFS_WATER() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        int nx, ny;
        for(int dir = 0; dir < 4; dir++) {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(vis[nx][ny]) continue;
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(arr[nx][ny] == 9 || arr[nx][ny] == 4) continue;
            vis[nx][ny] = vis[cur.first][cur.second] - 1;
            Q.push({nx, ny});
        }
    }
}

void DFS_S() {
    while(!P.empty()) {
        pair<int, int> cur = P.front(); P.pop();
        int nx, ny;
        for(int dir = 0; dir < 4; dir++) {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(vis2[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(arr[nx][ny] == 4) continue;
            vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
            P.push({nx, ny});
        }
    }
}

void DFS() {
    while(!S.empty()) {
        pair<int, int> cur = S.front(); S.pop();
        int nx, ny;
        for(int dir = 0; dir < 4; dir++) {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(arr[nx][ny] == 9 && !vis2[nx][ny]) {
                vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
            }
            if(vis[nx][ny] >= 0) continue;
            if(vis2[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
            S.push({nx, ny});
        }
    }
}

int main() {
    cin>>r>>c;
    int si, sj;
    for(int i = 0; i < r; i++) {
        cin>>s;
        for(int j = 0; j < c; j++) {
            if(s[j] == '.') arr[i][j] = 0;
            else if(s[j] == 'D') {
                arr[i][j] = 9;
                si = i;
                sj = j;
            }
            else if(s[j] == 'X') arr[i][j] = 4;
            else if(s[j] == '*') {
                vis[i][j]--;
                Q.push({i,j});
            }
            else if(s[j] == 'S') {
                arr[i][j] = 1;
                vis2[i][j]++;
                P.push({i, j});
                S.push({i, j});
            }
        }
    }
    DFS_WATER();
    DFS_S();
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!vis[i][j] && arr[i][j] != 4 && arr[i][j] != 9) vis[i][j]--;
            else vis[i][j] += vis2[i][j];
            vis2[i][j] = 0;
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == 1) {
                vis2[i][j]++;
            }
        }
    }
    DFS();
    if(!vis2[si][sj]) cout<<"KAKTUS";
    else cout<<vis2[si][sj] - 1;
}

/*
풀이

1. 물 bfs 돌려준다.
2. 고슴도치 bfs 돌려준다.
3. 둘의 방문 순서가 담긴 배열을 합쳐서 물이 먼저, 혹은 동시에 도착하면 고슴도치가 갈 수 없는 길이다.
4. 고슴도치가 갈 수 있는 길만으로 방문 순서가 담기는 bfs를 돌린다.
5. 도착지점(D)에 언제 도착하는지 출력하고, 도착하지 못한다면 KAKTUS를 출력한다.

bfs과정에서 벽의 표시에 유의한다.
*/