/*
https://www.acmicpc.net/problem/2295
백준 2295 세 수의 합
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[500500],tem[1000], n, coun;
bool func(int x) {
    int l = log2(coun) + 1;
    int fir = 0, end = coun - 1;
    while(l--) {
        int mid = (fir + end) / 2;
        if(arr[mid] > x) {
            end = mid;
        }
        else if(arr[mid] < x) {
            fir = mid;
        }
        else {
            return 1;
        }
    }
    return 0;
}
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) cin>>tem[i];
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            arr[coun++] = tem[i] + tem[j];
        }
    }
    int ans = 0;
    sort(arr, arr + coun);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int tmp = tem[j] - tem[i];
            if(func(tmp)) {
                ans < tem[j] ? ans = tem[j] : ans;
            }
        }
    }
    cout<<ans;
}

/*
풀이

x + y + z = k 인 수를 구하는 문제다.
이 식을
y + z = k - x 로 바꾸는 과정이 필요했다.
자연수의 종류는 최대 1000개로, 그 중 두 수의 모든 가능한 합을 만드는 것은 500500개면 된다.
k - x가 이 배열 안에 담겨있는지만 이분탐색으로 찾아, 그 중 최대를 출력한다.
*/