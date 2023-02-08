/*
https://www.acmicpc.net/problem/24041
백준 24041 성싶당 밀키트
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long arr[200001][3] = {}, n, germ, k, coun = 0;
    long long temp[200001] = {};
    cin>>n>>germ>>k;
    for(int i = 0; i < n; i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        if(arr[i][2]) coun++;
    }
    long long day = -1, ava = 0;
    long long start = 0, end = 3000000000;
    for(long long i = 0; i < log2(3000000000); i++) {
        long long mid = (start + end) / 2, temp_count = 0, temp_germ = 0;
        for(long long j = 0; j < n; j++) {
            if(arr[j][2]) {
                temp[temp_count++] = arr[j][0] * max<long long>(1, mid - arr[j][1]);
            }
            else {
                temp_germ += arr[j][0] * max<long long>(1, mid - arr[j][1]);
            }
        }
        sort(temp, temp + coun);

        for(long long j = coun - k - 1; j >= 0; j--) {
            temp_germ += temp[j];
        }
        if(temp_germ > germ) {
            end = mid;
        }
        else {
            start = mid;
            day = max(day, mid);
        }
    }
    cout<<day;
}

/*
풀이

며칠 후까지 먹을 수 있는지. 즉, 날짜에 대해서 이분탐색을 한다.
n번째 재료별로 있는 세균 중에 가장 값이 큰 것부터 k개를 제외한다.

이분탐색은 최댓값에 대해 신경을 써줘야하고, 이 문제의 경우 20억이 최대이다.
그 이상의 값을 입력할 경우 long long의 범위도 넘어갈 수 있으니, 최댓값을 찾는데에 신경쓴다.
*/