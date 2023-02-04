/*
https://www.acmicpc.net/problem/14999
백준 14499 주사위 굴리기
*/

#include <iostream>
using namespace std;
int arr[10][10] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};
int brr[20][20];
int dx[5] = {0, 1, -1,0,0}, dy[5] = {0, 0,0,-1,1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,dicex,dicey,n;
    cin>>x>>y>>dicex>>dicey>>n;
    int temp = n;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin>>brr[i][j];
        }
    }
    while(temp--) {
        cin>>n;
        if(dicex + dy[n] < 0 || dicey + dx[n] < 0) continue;
        if(dicex + dy[n] >= x || dicey + dx[n] >= y) continue;
        dicex += dy[n];
        dicey += dx[n];
        if(n == 4) {
            int temp = arr[0][1];
            for(int i = 0; i < 3; i++) {
                arr[i][1] = arr[i + 1][1];
            }
            arr[3][1] = temp;
        }
        else if(n == 3) {
            int temp = arr[3][1];
            for(int i = 3; i > 0; i--) {
                arr[i][1] = arr[i - 1][1];
            }
            arr[0][1] = temp;
        }
        else if(n == 2) {
            int temp = arr[3][1];
            arr[3][1] = arr[1][0];
            arr[1][0] = arr[1][1];
            arr[1][1] = arr[1][2];
            arr[1][2] = temp;
        }
        else if(n == 1) {
            int temp = arr[1][2];
            arr[1][2] = arr[1][1];
            arr[1][1] = arr[1][0];
            arr[1][0] = arr[3][1];
            arr[3][1] = temp;
        }
        if(brr[dicex][dicey] == 0) {
            brr[dicex][dicey] = arr[3][1];
        }
        else {
            arr[3][1] = brr[dicex][dicey];
            brr[dicex][dicey] = 0;
        }
        cout<<arr[1][1]<<'\n';
    }
}

/*
풀이

1. 주사위 굴리는 과정을 구현한다.

움직이면서 지도가 0이면 arr[3][1]을 지도에,
지도가 숫자면 arr[3][1]에 지도를 넣어주면 됨
+
매번 arr[1][1] (천장) 출력
*/