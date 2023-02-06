/*
https://www.acmicpc.net/problem/19590
백준 19590 비드맨
*/

#include <iostream>
#include <algorithm>
using namespace std;
long long n, m,k,arr[100001];
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    m = arr[n - 1];
    for(int i = 0; i < n - 1; i++) {
        k += arr[i];
    }
    if(m > k) cout<< m - k;
    else {
        if((m + k) % 2) cout<<1;
        else cout<<0;
    }
}

/*
풀이

그리디하게 푼다.

자유 이용권 문제에서 조금 더 생각하면 된다.
*/