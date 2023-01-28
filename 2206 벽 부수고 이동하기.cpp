/*
https://www.acmicpc.net/problem/2206
백준 2206 벽 부수고 이동하기
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;
string s;
queue<pair<pair<int, int>, int > > Q;
int arr[1000][1000], vis[1000][1000][2];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, n, m;

void func() {
    while(!Q.empty()) {

        pair<pair<int, int>, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            bool broke = cur.second;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(arr[nx][ny] && broke) continue; //벽이고 부딪힌 적 있으면
            if(!broke && vis[nx][ny][0]) continue;//벽, 0
            if(broke && vis[nx][ny][1]) continue;//벽, 1
            
            if(!broke) {
                if(!arr[nx][ny]) {
                    vis[nx][ny][0] = vis[cur.first.first][cur.first.second][0] + 1;
                    Q.push({{nx, ny}, 0});
                }
                if(arr[nx][ny]) {
                    vis[nx][ny][1] = vis[cur.first.first][cur.first.second][0] + 1;
                    Q.push({{nx, ny}, 1});
                }
            }
            else {
                if(!arr[nx][ny]) {
                    vis[nx][ny][1] = vis[cur.first.first][cur.first.second][1] + 1;
                    Q.push({{nx, ny}, 1});
                }
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>s;
        for(int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    vis[0][0][0] = 1;
    vis[0][0][1] = 1;
    Q.push({{0, 0}, 0});
    func();
    if(!vis[n - 1][m - 1][0] && !vis[n - 1][m - 1][1]) cout<<"-1";
    else if(vis[n - 1][m - 1][0] && vis[n - 1][m - 1][1]) cout<<min(vis[n - 1][m - 1][0], vis[n - 1][m - 1][1]);
    else cout<<max(vis[n - 1][m - 1][0], vis[n - 1][m - 1][1]);
}
/*
풀이

3개의 인자를 큐에서 받아서 해결한다.
여태 벽을 부쉈는지 여부를 담는 인자를 넣어서,
부수지 않은 경우, 부순 경우를 나눠서 푼다.

아직 부수지 않았을 경우, 
1. 벽을 만났을 때와
2. 벽을 만나지 않았을 경우를 나눠서 구현

이미 부순 경우,
1. 벽을 만나지 않았을 경우를 나눠서 구현

의 방식으로 해결할 수 있다.
*/