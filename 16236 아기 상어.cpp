/*
https://www.acmicpc.net/problem/16236
백준 16236 아기 상어
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int> >Q;
int ans;
int arr[20][20], vis[20][20], edible[20][20], n, shark_size = 2, ate = 0, available = 1;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int sharkx, sharky;

void find() { //가장 가까우면서 상단 좌측에 있는 것 찾기.
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;
            if(arr[nx][ny] > shark_size) {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                continue;
            }
            else if(arr[nx][ny] == shark_size || arr[nx][ny] == 0) {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
            else if(arr[nx][ny] < shark_size && arr[nx][ny]) {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                edible[nx][ny] = 1; //먹을 수 있는 물고기 체크
            }
        }
    }
    int mi = 100004;
    for(int i = 0; i < n; i++) { //가장 가까운 거리 찾기.
        for(int j = 0; j < n; j++) {
            if(edible[i][j]) {
                mi = min(mi, vis[i][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) { //최상단 좌측에 있는, 먹을 수 있는, 제일 가까운 물고기 찾기.
        for(int j = 0; j < n; j++) {
            if(edible[i][j] && vis[i][j] == mi) {
                sharkx = i;
                sharky = j;
                return;
            }
        }
    }
}
void func() {
    while(available) { //상어 못 먹을 때까지 반복
        available = 0;
        Q.push({sharkx, sharky});
        arr[sharkx][sharky] = 0;
        vis[sharkx][sharky] = 1;
        while(!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis[nx][ny]) continue;
                if(arr[nx][ny] > shark_size) {
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    continue;
                }
                else if(arr[nx][ny] == shark_size || arr[nx][ny] == 0) {
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    Q.push({nx, ny});
                }
                else if(arr[nx][ny] < shark_size && arr[nx][ny]) { //상어 위치 옮기기?
                    Q.push({cur.first, cur.second});
                    find();
                    ate++;
                    if(shark_size == ate) {
                        shark_size++;
                        ate = 0;
                    }
                    arr[sharkx][sharky] = 0;
                    available = 1;
                    ans += vis[sharkx][sharky] - 1;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
                edible[i][j] = vis[i][j] = 0;
            }
        }
    }
}

int main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 9) {
                sharkx = i;
                sharky = j;
            }
        }
    }
    func();
    cout<<ans;
}
/*
풀이

구현이 들어간 bfs 문제이다.

1. func 함수에서 상어 중심으로 먹을 수 있는 물고기를 찾고,
2. find 함수에서 그 중 가장 가까우면서 상단 좌측에 있는 물고기를 골라서,
3. func 함수에서 상어가 먹게 한 후, 상어를 옮겨주면 된다.
4. while 문을 통해 상어가 먹을 물고기가 없을 때까지 반복한다.
*/