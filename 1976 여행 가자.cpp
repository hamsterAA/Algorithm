/*
https://www.acmicpc.net/problem/1976
백준 1976 여행 가자
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool vis[1001];
queue<int> Q;
vector<int> v[1001];

bool bfs(int k, int tmp) {
    bool chk = 0;
    Q.push(k);
    vis[k] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == tmp) {
            chk = 1;
            break;
        }
        for(auto c : v[cur]) {
            if(vis[c]) continue;
            Q.push(c);
            vis[c] = 1;
        }
    }
    for(int i = 0; i < 201; i++) vis[i] = 0;
    return chk;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, tmp;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        v[i].push_back(i);
        for(int j = 1; j <= n; j++) {
            cin>>t;
            if(!t) continue;
            v[i].push_back(j);
            v[j].push_back(i);
        }
    }
    bool chk = 1;
    cin>>t;
    for(int i = 1; i < m; i++) {
        cin>>tmp;
        chk = 0;
        if(bfs(t, tmp)) {
            t = tmp;
            chk = 1;
        }
        else break;
    }
    if(!chk) cout<<"NO";
    else cout<<"YES";
}

/*
풀이

그래프를 입력받아서 그냥 순차대로,
각 도시에서 그 다음 도시까지 이동이 가능한지를 bfs로 확인하여
모든 도시에서 문제가 없다면 YES,
한 번이라도 끊긴다면 NO를 출력한다.
*/