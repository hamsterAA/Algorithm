/*
https://www.acmicpc.net/problem/7569
백준 7569 토마토
*/

#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[102][102][102];
int vis[102][102][102];
int n, m, h;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dh[6] = {0,0,0,0,1,-1};
queue<pair<pair<int,int>, int>> Q;
void bfs() {
    while(!Q.empty()){
        pair<pair<int,int>, int> cur = Q.front(); Q.pop();
        int nx, ny, nh;
        for(int dir = 0; dir < 6; dir++){
        nx = cur.X.X + dx[dir];
        ny = cur.X.Y + dy[dir];
        nh = cur.Y + dh[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h) continue;
        if(vis[nx][ny][nh]) continue;
        vis[nx][ny][nh] = vis[cur.X.X][cur.X.Y][cur.Y]+1;
        Q.push({{nx,ny}, nh});
        }
    }
    
    int day = 0;
    for(int k = 0; k < h; k++) {
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(day < vis[i][j][k]) day = vis[i][j][k];
                if(vis[i][j][k] == 0) {
                    cout<<-1;
                    return;
                }
            }
        }
    }
    cout<<day-1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>> n >> m >> h;
    for(int k = 0; k < h; k++) {
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                cin>>board[i][j][k];
                if(board[i][j][k] == 1) {
                    Q.push({{i,j},k});
                    vis[i][j][k] = 1;
                }
                else if(board[i][j][k] == -1){
                    vis[i][j][k] = -1;
                }
            }
        }
    }
    bfs();
    return 0;
}

/*
풀이

2차원 토마토 풀이와 비슷하게 푼다.
3개의 원소가 들어간 큐 
queue<pair<pair<int,int>,int>> Q 선언과,
Q.first.first, Q.second.first 등의 사용이 미숙했다.

어렵지 않은 문제였지만 마지막 날짜 확인 과정에서 토마토가 전부 익지 못하는 상황이 왔을 때,
vscode가 작동하지 않아 온라인 컴파일러로 보느라 식별이 잘 안 돼중첩문 탈출에서 어려움을 겪었다.

bfs를 함수로 분리하여 푸는 편이 가독성 면에서 더 낫다.
*/