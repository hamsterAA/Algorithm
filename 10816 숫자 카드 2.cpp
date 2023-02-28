/*
https://www.acmicpc.net/problem/10816
백준 10816 숫자 카드 2
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define tm 10000000
int n, m, arr[20000001], t;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    while(n--){
        cin>>m;
        arr[m + tm]++;
    }

    cin>>m;
    while(m--) {
        cin>>n;
        cout<<arr[n + tm]<<' ';
    }
}
/*
풀이

이분탐색 upper_bound, lower_bound 이용해서 푸는 문제인데, 
2000만 + 1개짜리 배열을 선언해서 풀어도 풀렸다.
숫자 크기를 좀 늘려야 의도에 맞게 풀도록 만들 수 있을 것 같다.

*/