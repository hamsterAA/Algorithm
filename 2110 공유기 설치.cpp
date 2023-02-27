/*
https://www.acmicpc.net/problem/2110
백준 2110 공유기 설치
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define bi 1000000000
int arr[200001], n, c;
void func() {
    int mid, fir = 0, end = bi - 1, ln = log2(bi) + 1, visIdx, ax = 0, ans = 0;
    while(ln--) {
        int cun = 1;
        ax = 1000000001;
        mid = (fir + end) / 2;
        int installed = arr[0];
        for(int i = 1; i < n; i++) {
            if(arr[i] - installed >= mid) {
                if(ax > arr[i] - installed) {
                    ax = arr[i] - installed;
                }
                cun++;
                installed = arr[i];
            }
        }
        if(cun < c) end = mid;
        else if(cun >= c && ans < ax) {
            ans = ax;
            fir = mid;
        }
        else if(cun >= c && ans > ax) {
            end = mid;
        }
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>c;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    func();
}
/*
풀이

정말 많이 틀렸다.

집 사이의 거리에 대해서 매개변수탐색을 진행하는데,
1. 전에 설치된 집을 기준으로 거리를 계산하며,
2. 거리를 만족하는 집이 공유기의 개수 보다 많다면 그것도 인정해줘야한다.

이 2가지를 신경쓰지 못해서 접근 방식을 이해 못했다.
*/