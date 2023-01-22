/*
https://www.acmicpc.net/problem/15683
백준 15683 감시
*/

#include <iostream>
using namespace std;
int cctv[10][4], arr[8][8];
int n, m, cctv_num;
int dx_1[4] = {0, 0, 1, -1}, dy_1[4] = {1, -1, 0, 0};
int dx_3[4] = {0, 1, 0, -1}, dy_3[4] = {1, 0, -1, 0};
void watch(int k) {
    int whatcctv = cctv[k][0];
    int start_n = cctv[k][1];
    int start_m = cctv[k][2];
    int direction = cctv[k][3];

    if(whatcctv == 1) { //Completed
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_1[direction];
            start_m += dy_1[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
    }

    else if(whatcctv == 2) { //inCompleted
        if(direction % 2) {
            while(arr[start_n][start_m] != 6) {
                arr[start_n][start_m] = 9;
                start_n++;
                if(start_n >= n) break;
            }
            start_n = cctv[k][1];
            while(arr[start_n][start_m] != 6) {
                arr[start_n][start_m] = 9;
                start_n--;
                if(start_n < 0) break;
            }
        }
        else {
            while(arr[start_n][start_m] != 6) {
                arr[start_n][start_m] = 9;
                start_m++;
                if(start_m >= m) break;
            }
            start_m = cctv[k][2];
            while(arr[start_n][start_m] != 6) {
                arr[start_n][start_m] = 9;
                start_m--;
                if(start_m < 0) break;
            }
        }
    }

    else if(whatcctv == 3) {
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_3[direction];
            start_m += dy_3[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
        direction++;
        direction %= 4;
        start_n = cctv[k][1];
        start_m = cctv[k][2];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_3[direction];
            start_m += dy_3[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
    }
    else if(whatcctv == 4) {
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_1[direction];
            start_m += dy_1[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
        direction++;
        direction %= 4;
        start_n = cctv[k][1];
        start_m = cctv[k][2];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_1[direction];
            start_m += dy_1[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
        direction++;
        direction %= 4;
        start_n = cctv[k][1];
        start_m = cctv[k][2];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n += dx_1[direction];
            start_m += dy_1[direction];
            if(start_n < 0 || start_n >= n || start_m < 0 || start_m >= m) break;
        }
    }

    else if(whatcctv == 5) { //Completed
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n++;
            if(start_n >= n) break;
        }
        start_n = cctv[k][1];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_n--;
            if(start_n < 0) break;
        }
        start_n = cctv[k][1];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_m++;
            if(start_m >= m) break;
        }
        start_m = cctv[k][2];
        while(arr[start_n][start_m] != 6) {
            arr[start_n][start_m] = 9;
            start_m--;
            if(start_m < 0) break;
        }
    }
}
int ans = 100000, temp;
void func(int k) {
    if(k == cctv_num) {
        for(int i = 0; i < cctv_num; i++) {
            watch(i);
        }
        temp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!arr[i][j]) temp++;
                if(arr[i][j] != 6) arr[i][j] = 0;
            }
        }
        ans = min(ans, temp);
        return;
    }
    for(int i = 0; i < 4; i++) {
        cctv[k][3] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6) {
                cctv[cctv_num][0] = arr[i][j];
                cctv[cctv_num][1] = i;
                cctv[cctv_num][2] = j;
                cctv_num++;
            }
        }
    }
    func(0);
    cout<<ans;
}

/*
풀이

1. 백트래킹을 이용해 cctv를 90도씩 모두 돌릴 수 있도록 모든 경우의 방향을 구한다.
2. 벽을 만나기 전까지 만나는 감시 가능한 영역을 9로 채운다.
3. 모든 cctv에 대해 탐색이 끝나면 탐색이 불가능했던 영역의 넓이를 구한다.
*/