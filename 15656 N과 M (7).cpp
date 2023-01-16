/*
https://www.acmicpc.net/problem/15656
백준 15656 이름 N과 M (7)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10],brr[10], n, m;
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout<<brr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(1) {
            isused[i] = 1;
            brr[k] = arr[i];
            func(k + 1);
            //isused[i] = 0;
        }
        isused[i] = 0;
    }
}
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    func(0);
}

/*
풀이

중복 포함하지 않는 백트래킹 구현 후,
isused를 의미 없도록 만들었다.
*/