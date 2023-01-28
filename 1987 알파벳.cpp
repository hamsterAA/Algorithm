/*
https://www.acmicpc.net/problem/1987
백준 1987 알파벳
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
string s;
stack<pair<int, int> > S;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, ans = 1;
int arr[21][21], alpha[90], vis[21][21], n, m;

void DFS(int first, int second) {
    for(int dir = 0; dir < 4; dir++) {
        int nx = first + dx[dir];
        int ny = second + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(vis[nx][ny]) continue; //방문한 곳
        if(alpha[arr[nx][ny]]) continue; //방문한 알파벳

        vis[nx][ny] = vis[first][second] + 1;
        ans = max(ans, vis[nx][ny]);
        alpha[arr[nx][ny]] = 1;

        DFS(nx, ny);
        
        alpha[arr[nx][ny]] = 0; //탐색 후 방문하지 않은 것으로 처리
        vis[nx][ny]  = 0;
    }
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>s;
        for(int j = 0; j < m; j++) {
            arr[i][j] = s[j];
        }
    }
    vis[0][0] = 1;
    alpha[arr[0][0]] = 1;
    DFS(0,0);
    cout<<ans;
}
/*
풀이

DFS와 백트래킹을 적절히 섞어서 구현했다.
기존에 DFS에서 저장된 nx와 ny를 이용하여 백트래킹 과정에서 그래프 탐색을 하는 것이 핵심이다.

로직은, 
이미 사용된 문자를 만나거나,
같은 경로 상에서 방문한 곳을 재방문 할 경우 되돌아가는 방식이다.
*/