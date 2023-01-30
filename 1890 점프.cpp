/*
https://www.acmicpc.net/problem/1890
백준 1890 점프
*/

#include <iostream>
using namespace std;
long long n, arr[100][100], vis[100][100] = {1};
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n - 1 && j == n - 1) break;
            if(i + arr[i][j] < n) {
                vis[i + arr[i][j]][j] += vis[i][j];
            }
            if(j + arr[i][j] < n) {
                vis[i][j + arr[i][j]] += vis[i][j];
            }
        }
    }
    cout<<vis[n - 1][n - 1];
}

/*
풀이

경로의 개수가 2^63 - 1 까지 될 수 있기에 long long으로 선언해줘야한다. (여기서 틀렸다.)
그 이외에는 위에서 아래로, 혹은 왼쪽에서 오른쪽으로의 진행방향에 상관없이 풀 수 있다.
*/