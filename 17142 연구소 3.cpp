#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, virus, ans = 10000000;
int arr[50][50], vis[50][50], v_vis[10];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<pair<int, int> > v;
queue<pair<int, int> > Q;
int bfs() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;
            Q.push(make_pair(nx, ny));
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] > tmp && arr[i][j] != 2) tmp = vis[i][j];
            if(vis[i][j] == 0) tmp = 10000000;
            vis[i][j] = 0;
            if(arr[i][j] == 1) vis[i][j] = 1;
        }
    }
    return tmp;
}
void func(int before, int k) {
    if(k == m) {
        for(int i = 0; i < virus; i++) {
            if(v_vis[i]) {
                vis[v[i].first][v[i].second] = 1;
                Q.push(make_pair(v[i].first, v[i].second));
            }
        }
        int tmp = bfs();
        if(tmp < ans) ans = tmp;
    }

    for(int i = before; i < virus; i++) {
        if(!v_vis[i]) {
            v_vis[i] = 1;
            func(i, k + 1);
            v_vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 2) {
                v.push_back(make_pair(i, j));
                virus++;
            }
            else if(arr[i][j] == 1) {
                vis[i][j] = 1;
            }
        }
    }
    func(0, 0);
    if(ans == 10000000) cout<<-1;
    else cout<<ans - 1;
}