/*
https://www.acmicpc.net/problem/13913
백준 13913 숨바꼭질 4
*/

#include <iostream>
#include <queue>
using namespace std;
int arr[100001][2], dx[3] = {1, -1, 2}, n, m, coun, ans[100001];
queue <int> Q;

void bfs(int k) {
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == m) {
            cout<<arr[cur][0] - 1<<'\n'; 
            break;
        }
        for(int i = 0; i < 3; i++) {
            int nx = cur;
            if(i != 2) nx += dx[i];
            else nx *= 2;
            if(nx > 100000 || nx < 0) continue;
            if(arr[nx][0]) continue;
            arr[nx][0] = arr[cur][0] + 1;
            arr[nx][1] = cur; //큐에 넣는 새로 만들어진 숫자에 경로 넣기.
            Q.push(nx);
        }
    }
}

int main() {
    cin>>n>>m;
    int temp = m;
    arr[n][0]++;
    Q.push(n);
    bfs(n);

    while(m != n) {
        ans[coun++] = m = arr[m][1];
    }
    for(int i = coun - 1; i >= 0; i--) cout<<ans[i]<<' ';
    cout<<temp;
}

/*
풀이

이전의 경로를 찾아갈 수 있도록,
bfs 과정에서 이전의 숫자를 배열에 넣어준다.

코드는 어렵지 않고, 아이디어도 어렵지 않은 것 같은데, 떠올리기가 힘들었다.
*/