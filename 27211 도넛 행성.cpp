/*
https://www.acmicpc.net/problem/27211
백준 27211 도넛 행성
*/

#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int n, m, h;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> Q;
void bfs() {
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        int nx, ny;
        for(int dir = 0; dir < 4; dir++){
        nx = cur.X + dx[dir];
        ny = cur.Y + dy[dir];
        if(nx < 0) nx = m - 1;
        else if(nx >= m) nx = 0;
        else if(ny < 0) ny = n - 1;
        else if(ny >= n) ny = 0;
        if(board[nx][ny]) continue;
        board[nx][ny] = 1;
        Q.push({nx,ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>> n >> m;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            cin>>board[i][j];
        }
    }
    int count = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            if(!board[i][j]) {
                Q.push({i, j});
                bfs();
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}

/*
풀이

일단 배열을 전부 입력받은 후, 배열 전체를 탐색하면서 0이 등장하면 bfs를 한다.
영역 밖으로 나가는 경우에 반대편으로 들어오게 해주기만 하면 된다.
나머지는 기초적인 BFS와 동일하다.

방문했는지 확인할 필요가 없기 때문에 메모리를 더 조금 사용해서 풀 수 있다.
백준 120명 중 4등.

*/