/*
https://www.acmicpc.net/problem/2638
백준 2638 치즈
*/

#include <iostream>
#include <queue>
using namespace std;

int board[101][101];
int vis[101][101];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int ans = -1,check = 1;
queue<pair<int,int> > Q;

void bfs() {
    check = 0;
            Q.push({0, 0});
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                if(vis[cur.first][cur.second]) continue;
                vis[cur.first][cur.second]++;
                int nx, ny;
                for(int dir = 0; dir < 4; dir++){
                    nx = cur.first + dx[dir];
                    ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!board[nx][ny] && vis[nx][ny]) continue;
                    if(board[nx][ny]) {
                        vis[nx][ny]++;
                        continue;
                    }
                    Q.push({nx,ny});
                }
            }
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] >= 2) {
                board[i][j] = 0;
                check++;
            }
            vis[i][j] = 0;
        }
    }
    ans++;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>board[i][j];
        }
    }

    while(check) {
        bfs();
    }

    cout<<ans;
}

/*
풀이

1. 가장자리는 무조건 공기니까, 항상 (0,0)을 큐에 넣어준다.
2. 치즈 밖에 있는 공기만으로 공기의 접촉을 계산하니, bfs를 돌리며 치즈와 만나면 1씩 더해준다.
3. 치즈가 공기와 2번 이상 접촉했으면 치즈를 공기로 바꿔준다.
4. vis 배열을 초기화 시킨 후, 1번부터 반복한다.

치즈가 전부 사라질 때까지 이를 반복해서 풀 수 있다.
*/