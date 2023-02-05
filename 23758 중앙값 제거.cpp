/*
https://www.acmicpc.net/problem/23758
백준 23758 중앙값 제거
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[2000001], n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    for(int i = 1; i < (n + 1) / 2; i++) {
        cout<<arr[i]<<' '<<log2(arr[i])<<'\n';
        ans += log2(arr[i]);
    }
    ans += log2(arr[0]) + 1;
    cout<<ans;
}
/*
풀이

정렬 후,
중앙값까지의 모든 값이 1이 되도록 만들어준다.
그 후 1을 한 번만 더 나누면 0이 된다.
*/