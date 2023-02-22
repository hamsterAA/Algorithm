/*
https://www.acmicpc.net/problem/9465
백준 9465 스티커
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][100001], dp[2][100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int j = 0; j < 2; j++) {
            for(int i = 0; i < n; i++) {
                cin>>arr[j][i];
            }
        }
        dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1]; dp[1][1] = arr[0][0] + arr[1][1];
        for(int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }
        cout<<max(dp[0][n - 1], dp[1][n - 1])<<'\n';
    }
}

/*
풀이

2차원 배열에서의 dp문제이다.

상하좌우를 고르지 못하니 진행방향은 상하가 될 수 없고,
옆으로 갈 때 어떤 스티커를 골라야 겹치지 않는지 신경써주면 된다.
*/