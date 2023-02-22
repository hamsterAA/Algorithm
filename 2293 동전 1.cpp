/*
https://www.acmicpc.net/problem/2293
백준 2293 동전 1
*/

#include <iostream>
using namespace std;

int arr[10001], dp[10001], n, m;
int main() {
    cin>>n>>m;
    dp[0] = 1;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j - arr[i] >= 0) {
                dp[j] += dp[j - arr[i]]; 
            }
        }
    }
    cout<<dp[m];
}

/*
풀이

https://velog.velcdn.com/images/jxlhe46/post/2469a437-85e0-4316-858b-07920259585d/image.jpg

이 사진이 엄청 도움됐다.
감이 안 잡혔는데, 

k원을 사용하지 않았을 때 만들 수 있는 경우의 수
+
k원을 사용할 때 n - k 원으로부터 만들 수 있는 경우의 수

가 핵심이다.
*/