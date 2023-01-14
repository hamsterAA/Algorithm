/*
https://www.acmicpc.net/problem/15664
백준 15664 N과 M (10)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], brr[10], n, m;
bool isused[10];
void func(int k) {
    if(k == m + 1) {
        for(int i = 1; i <= m; i++) {
            cout<<brr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int temp = -1;
    for(int i = 0; i < n; i++) {
        if(!isused[i] && temp != arr[i]) {
            brr[k] = arr[i];
            if(brr[k] < brr[k - 1]) continue;
            temp = arr[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    func(1);
}

/*
풀이

N과 M (9)과 같이
백트래킹 함수 안에 temp 선언해서 중복을 제거해주고,
continue를 사용해 비내림차순만 뽑아낸다.
*/