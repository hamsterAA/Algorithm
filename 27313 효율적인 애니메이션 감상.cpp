/*
https://www.acmicpc.net/problem/27313
백준 27313 효율적인 애니메이션 감상
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long arr[100000],n,m,k,tmp,ans = -1,fir,e,mid, coun;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    
    fir = 0;
    e = n;
    for(int i = 0; i < log2(100000); i++) {
        tmp = coun = 0;
        mid = (fir + e) / 2;
        for(int j = mid; j >= 0; j -= k) {
            coun++;
            tmp += arr[j];
        }
        if(tmp <= m) {
            ans = max(ans, coun);
            fir = mid;
        }
        else {
            e = mid;
        }
    }
    if(arr[fir] > m) cout<<0;
    else cout<<fir + 1;
}

/*
풀이

이분탐색을 이용해서 푼다.
힌트를 보고도 무슨 말인지 한참을 생각했다.

동시에 보는 애니메이션 k개는 고정하고,
한별이가 볼 수 있는 애니메이션 개수에 대해서 이분탐색을 한다.
*/