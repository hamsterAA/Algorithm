/*
https://www.acmicpc.net/problem/1261
백준 1261 알고스팟
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;
string s;
queue<pair<int, int> > Q;
int arr[100][100], vis[100][100] = {1};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, n, m;

void func() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(arr[nx][ny]) {
                if(!vis[nx][ny]) {
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    Q.push({nx, ny});
                }
                else {
                	if(vis[nx][ny] > vis[cur.first][cur.second] + 1) {
                		vis[nx][ny] = vis[cur.first][cur.second] + 1;
                		Q.push({nx, ny});
                	}
                }
            }
            else {
                if(vis[nx][ny]) {
                    if(vis[nx][ny] > vis[cur.first][cur.second]) {
                        vis[nx][ny] = vis[cur.first][cur.second];
                        Q.push({nx, ny});
                    }
                }
                else {
                    vis[nx][ny] = vis[cur.first][cur.second];
                    Q.push({nx, ny});
                }
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        cin>>s;
        for(int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    Q.push({0, 0});
    func();
    cout<<vis[m - 1][n - 1] - 1;
}
/*
풀이

배열이 1일 경우와 0일 경우를 나눠서 생각하면 된다.
*/