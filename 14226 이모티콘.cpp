/*
https://www.acmicpc.net/problem/14226
백준 14226 이모티콘
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int> > Q;
int arr[1001][1001], vis[1001][1001] = {1}, n;

void func() {
    while(!Q.empty()) {
    pair<int, int> cur = Q.front();Q.pop();
        int nx = cur.first;
        int ny = cur.second;//clipboard
        if(nx == n) {
            cout<<vis[nx][ny];
            return;
        }
        if(nx - 1 > 0 && !vis[nx - 1][ny]) {
            vis[nx - 1][ny] = vis[nx][ny] + 1;
            Q.push({nx - 1, ny});
        }
        if(nx <= 1000 && !vis[nx][nx]) {
            vis[nx][nx] = vis[nx][ny] + 1;
            Q.push({nx, nx});
        }
        if(nx + ny <= 1000 && !vis[nx + ny][ny]) {
            vis[nx + ny][ny] = vis[nx][ny] + 1;
            Q.push({nx + ny, ny});
        }
    }
}

int main() {
    cin>>n;
    Q.push({1, 0});
    func();
}

/*
풀이

복사, 붙여넣기, 삭제하는 경우에 대해서 bfs로 탐색한다.

1. 24ms 풀이

1에서 1000 사이의 클립보드에 복사된 이모티콘이 있을 때,
n개의 이모티콘을 만드는데에 가장 짧은 시간이 든 경우를 출력한다.

2. 4ms 풀이

위와 동일하게 탐색하나, 
n개의 이모티콘이 만들어진 시점에 바로 출력한다.
가중치가 동일한 bfs 이기에,
목표치의 이모티콘이 처음 만들어진 때가 최단시간이라는 것이 보장된다.
*/