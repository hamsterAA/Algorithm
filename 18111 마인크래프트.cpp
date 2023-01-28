/*
https://www.acmicpc.net/problem/18111
백준 18111 마인크래프트
*/

#include <iostream>
using namespace std;
int arr[501][501], n, m, b, ans = 100000000, height = -1;

int main() {
    cin>>n>>m>>b;
    for(int i = 0; i < n; i++) { //입력
        for(int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }

    int te = 256; //목표 높이
    while(te + 1) { //목표 높이 0까지 탐색해야 하기에, te + 1;
        int need = 0, inv = b, dig = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(te > arr[i][j]) { //목표 높이가 블럭보다 높으면 
                    need += te - arr[i][j]; //차이만큼 쌓아야함
                }
                else { //아니면 파서 인벤토리에 넣기
                    inv += arr[i][j] - te;
                    dig += arr[i][j] - te;
                }
            }
        }
        if(inv >= need) {
            if(ans > need + dig * 2) {//쌓는 것(need)는 1초, 파는 것(dig)는 2초
                ans = need + dig * 2;
                height = te;
            }
        }
        te--;
    }
    cout<<ans<<' '<<height;
}

/*
풀이

0~256까지 목표 높이를 설정해두고
브루트포스로 풀 수 있었다.

기존 인벤토리에 있던 블럭 + 추가로 판 블럭 < 쌓는데에 필요한 블럭
일 경우, 계산을 건너뛰어준다.
*/