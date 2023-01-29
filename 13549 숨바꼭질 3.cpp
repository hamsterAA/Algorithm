/*
https://www.acmicpc.net/problem/13549
백준 13549 숨바꼭질 3
*/

#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int vis[100001], n, k;
int dx[2] = {-1, 1};

void func() {
    while(!dq.empty()) {
        int temp = dq.front(); dq.pop_front();
        for(int i = 2; i >= 0; i--) {
            int nx;
            if(i < 2) nx = temp + dx[i];
            else nx = temp * 2;
            if(nx < 0 || nx > 100000) continue;
            if(vis[nx]) continue;
            if(i == 2) {
                vis[nx] = vis[temp];
                dq.push_front(nx);
            }
            else {
                vis[nx] = vis[temp] + 1;
                dq.push_back(nx);
            }
        }
    }
    cout<<vis[k] - 1;
}

int main() {
    cin>>n>>k;

    dq.push_front(n);
    vis[n] = 1;

    func();
}

/*
풀이

queue가 아니라 deque를 이용한다.
가중치가 0, 1 뿐이라, 0-1 너비 우선 탐색으로 푼다.

pop 이전에 방문체크를 해주기에,
이동하는데에 시간이 들지 않는 
X * 2 위치로의 이동을 먼저 체크해주는 것이 중요하다.
↑
이것 때문에 어떻게 풀어야할지 알고도 한 번 틀렸다.
*/