/*
https://www.acmicpc.net/problem/11659
백준 11659 구간 합 구하기 4
*/

#include <iostream>
using namespace std;

int arr[100002], n, m, f, e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        cin>>arr[i];
        arr[i] += arr[i - 1];
    }
    while(m--) {
        cin>>f>>e;
        cout<<arr[e] - arr[f - 1]<<'\n';
    }
}

/*
풀이

누적 합을 이용해서 간단하게 풀 수 있다.
i번째 부터 j번째까지에 유의하여,
arr[j] - arr[i - 1]을 출력한다.
*/