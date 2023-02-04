/*
https://www.acmicpc.net/problem/25635
백준 25635 자유 이용권
*/

#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001], t, biggest, rest;
int main() {
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>arr[i];
    }
    sort(arr, arr + t);
    biggest = arr[t - 1];
    for(int i = 0; i < t - 1; i++) {
        rest += arr[i];
    }
    if(biggest > rest) cout<<rest * 2 + 1;
    else cout<<rest + biggest;
}
/*
풀이

재밌는 그리디이다.

가장 많은 것과 나머지로 나눠서 생각한다.

만약 가장 많은 횟수보다 다른 것들의 횟수가 더 많다면,
번갈아가면서 타면 티켓을 전부 소진할 수 있다.

그렇지 않다면,
가장 많은 것부터 교대로 번갈아가며 탔을 때,
나머지만큼 탄 후 가장 많은 것을 한 번 더 탈 수 있다.
*/