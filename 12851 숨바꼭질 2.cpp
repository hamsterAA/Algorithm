/*
https://www.acmicpc.net/problem/12851
백준 12851 숨바꼭질 2
*/

#include <iostream>
#include <queue>
using namespace std;
int arr[100001], n, k, vis[100001], ans, tim;
int dx[3] = {1, -1, 2};
queue<pair<int, int> > Q;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    Q.push({n, 1});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        int nx = cur.first; int t = cur.second;
        vis[nx]++;
        if(nx == k && !tim) {
            ans = t;
            tim++;
        }
        else if(nx == k && ans == t) {
            tim++;
        }
        for(int dir = 0; dir < 3; dir++) {
            int temp = nx;
            if(dir < 2) {
                temp += dx[dir];
            }
            else temp *= dx[dir];
            if(temp < 0 || temp > 100000 || vis[temp]) continue;
            Q.push({temp, t + 1});
        }
    }

    cout<<ans - 1<<'\n'<<tim;
}

/*
풀이

수빈이가 동생을 찾는 가장 빠른 시간 ans,
가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수 tim.
2가지 변수를 선언한다.
↓
동생을 찾는 방법을 처음 찾았다면, 
ans에 걸린 시간, tim에 1을 더해준다.
↓
동생을 찾는 방법을 또 찾고, 경과 시간이 같다면 (ans == t) 
tim에 1을 더해준다.

큐가 완전히 비면 정답을 출력한다.
*/