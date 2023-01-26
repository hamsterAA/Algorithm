/*
https://www.acmicpc.net/problem/2573
백준 2573 빙산
*/

#include <iostream>
#include <queue>
using namespace std;
int arr[300][300], n, m, brr[300][300], coun,vis[300][300], check;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0,0,1,-1}, year;
queue<pair<int, int> > Q;

void bfs() {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); 
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(vis[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!arr[nx][ny]) {
                brr[cur.first][cur.second]--;
            }
            if(arr[nx][ny]) {
            	Q.push({nx, ny});
            	vis[nx][ny]++;
            }
        }
    }
}

void bff() {
	while(!Q.empty()) {
		pair<int, int> cur = Q.front(); 
		Q.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(vis[nx][ny]) continue;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(arr[nx][ny]) {
				vis[nx][ny] = coun;
				Q.push({nx, ny});
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>arr[i][j];
		}
	}
    do {
    	coun = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] && !vis[i][j]) {
                    Q.push({i, j});
                    vis[i][j]++;
                    bfs();
                }
            }
    	}
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] += brr[i][j];
                if(arr[i][j] < 0) arr[i][j] = 0;
                brr[i][j] = vis[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(arr[i][j] && !vis[i][j]) {
        			coun++;
        			Q.push({i, j});
        			vis[i][j] = coun;
        			bff();
        		}
        	}
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
        year++;
    } while(coun == 1);
    if(coun) cout<<year;
    else cout<<0;
}

/*
풀이

0. 배열 arr에 빙산의 정보를 입력한다.
1. bfs로 빙산이 있는 곳만 탐색하며, 주위에 물이 있으면 배열 brr에 따로 저장한다.
2. 배열 arr에 녹은 빙산의 정보를 업데이트 해준다.
3. bfs로 빙산이 2개 이상인지, 1개인지, 0개인지 탐색한다.
4. 빙산이 한 개라면 2번부터 반복한다.
5. 2개 이상이라면 걸린 시간, 0개라면 전부 녹은 것으로 '0'을 출력한다.
*/