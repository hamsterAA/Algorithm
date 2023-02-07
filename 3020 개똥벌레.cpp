/*
https://www.acmicpc.net/problem/3020
백준 3020 개똥벌레
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,arr[100001], brr[100001], a, b;
int func(int *param, double k) {
    int start = 0, end = a - 1, mid;
    for(int i = 0; i < log2(a); i++) {
        mid = (start + end) / 2;
        if(param[mid] > k) {
            end = mid;
        }
        else {
            start = mid;
        }
    }
    if(param[0] > k) start--;
    if(param[end] < k) start++;
    return start + 1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        if(i % 2) {
            cin>>brr[b++];
            brr[b - 1] = m - brr[b - 1];
        }
        else cin>>arr[a++];
    }
    sort(arr, arr + a); sort(brr, brr + b);
    
    int Min = 10000000, coun = 0;
    for(double i = 0.5; i < m; i++) {
        int under = a - func(arr, i); //i 높이로 날 때 부딪히는 석순
        int upper = func(brr, i); //i 높이로 날 때 부딪히는 종유석
        if(under + upper < Min) {
            Min = under + upper;
            coun = 1;
        }
        else if(Min == under + upper) {
            coun++;
        }
    }
    cout<<Min<<' '<<coun;
}

/*
풀이

개똥벌레가 나는 높이를 고정해두고,
각각의 높이에서 몇개의 석순과 종유석과 부딪히는지 이분 탐색
*/