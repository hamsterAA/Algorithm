/*
https://www.acmicpc.net/problem/17144
백준 17144 미세먼지 안녕!
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[50][50], tempArr[50][50], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, t, cleanserx, cleansery, cleanserx2, cleansery2, ans;

void dust() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] > 4) {
                int dustDiv5 = arr[i][j] / 5;
                for(int dir  = 0; dir < 4; dir++) {
                    if(i + dx[dir] < 0 || i + dx[dir] >= n || j + dy[dir] < 0 || j + dy[dir] >= m) continue;
                    if(arr[i + dx[dir]][j] == -1 || arr[i][j + dy[dir]] == -1) continue;
                    tempArr[i+dx[dir]][j+dy[dir]] += dustDiv5;
                    arr[i][j] -= dustDiv5;
                }
            }
        }
    }
}
void dustSum() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] += tempArr[i][j];
            tempArr[i][j] = 0;
        }
    }
}

void wind() {
    for(int i = cleansery - 1; i > 0; i--){
        arr[i][0] = arr[i - 1][0];
    }
    for(int i = 0; i < m - 1; i++){
        arr[0][i] = arr[0][i + 1];
    }
    for(int i = 0; i < cleansery; i++){
        arr[i][m - 1] = arr[i + 1][m - 1];
    }
    for(int i = m - 1; i > 1; i--){
        arr[cleansery][i] = arr[cleansery][i - 1];
    }
    arr[cleansery][cleanserx + 1] = 0;

    for(int i = cleansery2 + 1; i < n - 1; i++){
        arr[i][0] = arr[i + 1][0];
    }
    for(int i = 0; i < m - 1; i++){
        arr[n - 1][i] = arr[n - 1][i + 1];
    }
    for(int i = n - 1; i > cleansery2 - 1; i--){
        arr[i][m - 1] = arr[i - 1][m - 1];
    }
    for(int i = m - 1; i > 1; i--){
        arr[cleansery2][i] = arr[cleansery2][i - 1];
    }
    arr[cleansery2][cleanserx2 + 1] = 0;
}
void sum() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += arr[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == -1 && !cleansery) {
                cleanserx = j;
                cleansery = i;
                cleanserx2 = j;
                cleansery2 = i + 1;
            }
        }
    }
    while(t--) {
        dust();
        dustSum();
        wind();
    }
    sum();
    cout<<ans + 2;
}
/*
풀이

1. 미세먼지를 확산시킨다. 구현을 위해 배열을 2개 사용한다.
2. 공기청정기를 기점으로 순환시킨다.
위의 내용을 구현해주면 된다.

배열에서의 회전 구현을 연습하기 위해 풀어봤다. 
23/2/24
*/