/*
https://www.acmicpc.net/problem/1253
백준 1253 좋다
*/

#include <iostream>
#include <algorithm>
using namespace std;
long long arr[2000], n, ans;
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        long long start = 0, end = n - 1;
        while(1) {
            if(start == i) {
                start++;
            }
            if(end == i) {
                end--;
            }
            if(start == end) break;
            if(arr[start] + arr[end] < arr[i]) {
                start++;
            }
            else if(arr[start] + arr[end] > arr[i]) {
                end--;
            }
            else {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}

/*
풀이

입력되는 수에 0과 음수가 있기에,
그리고 '어떤 수'를 '다른 두 수'의 합으로 나타내야 한다.

그렇기에 제일 앞, 뒤에서부터 투 포인터로 좋은 수가 될 수 있는지 탐색하며,
'다른 두 수'를 고를 때 '어떤 수'를 고르지 않도록 조건을 넣어준다.
*/