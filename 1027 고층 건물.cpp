/*
https://www.acmicpc.net/problem/1027
백준 1027 고층 건물
*/

#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100], n, tmp, ccw, ans = 0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i= 0; i < n; i++) cin>>arr[i];
    for(int i = 0; i < n; i++) {
        bool flag = 0;
        tmp = 0;
        for(int j = i - 2; j >= 0; j--) {
            for(int k = j + 1; k < i; k++) {
                ccw = (k - j) * (arr[i] - arr[j]) - (i - j) * (arr[k] - arr[j]);
                if(ccw <= 0) {
                    flag = 1;
                    break;
                }
            }
        if(!flag) tmp++;
        flag = 0;
        }
        flag = 0;
        for(int j = i + 2; j < n; j++) {
            for(int k = j - 1; k > i; k--) {
                ccw = (k - i) * (arr[j] - arr[i]) - (j - i) * (arr[k] - arr[i]);
                if(ccw <= 0) {
                    flag = 1;
                    break;
                }
            }
        if(!flag) tmp++;
        flag = 0;
        }
        ans = max(ans, tmp);
    }
    cout<<ans;
}

/*
풀이

ccw 알고리즘을 이용해서 풀 수 있다.
두 지붕을 잇는 선분이 다른 빌딩에 접하지도 않아야 하기에,
구한 ccw의 값이 0 이하이면 보이지 않는 것으로 한다.
*/