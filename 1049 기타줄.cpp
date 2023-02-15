/*
https://www.acmicpc.net/problem/1049
백준 1049 기타줄
*/

#include <iostream>
#include <algorithm>
using namespace std;
int n,m, arr[151], brr[51];

int main() {
    cin>>n>>m;
    int cheap = 0;
    for(int i = 0; i < m; i++) {
        cin>>arr[i + cheap];
        cin>>brr[i];
        if(brr[i] * 6 < arr[0]) {
            cheap++;
            arr[i + cheap] = brr[i] * 6;
        }
    }
    sort(arr, arr + m + cheap);
    sort(brr, brr + m);
    int pack = n / 6, piece = n % 6;
    int ans = pack * arr[0];
    if(arr[0] > piece * brr[0]) ans += piece * brr[0];
    else if(piece) ans += arr[0];
    cout<<ans;
}

/*
풀이

1. 묶음이 낱개보다 저렴한 경우
2. 묶음보다 낱개 6개가 저렴한 경우
를 나눠서 처리해준다.
*/