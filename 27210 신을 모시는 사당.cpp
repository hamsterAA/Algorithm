/*
https://www.acmicpc.net/problem/27210
백준 27210 신을 모시는 사당
*/

#include <iostream>
#include <cmath>
using namespace std;
int arr[100001];
int ans[100002];

int main() {
    int n, max = 0, min = 0;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    if(arr[0] == 1) ans[0] = 1;
    else ans[0] = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == 1) ans[i] = ans[i - 1] + 1;
        else ans[i] = ans[i - 1] - 1;
    }for(int i =0; i < n; i++) {
        if(max < ans[i]) max = ans[i];
        if(min > ans[i]) min = ans[i];
    }
    cout<<abs(max - min);

}

/*
풀이

누적합을 이용해서 풀 수 있다.
예를 들어 최댓값이 등장한 구간 - 최솟값이 등장한 구간을 구하면,
최댓값에서부터 최솟값으로까지의 차이만큼을 구할 수 있는 것으로,
구간 안에서 최대의 절댓값이다.

누적합에서의 | 최댓값 - 최솟값 | 을 통해, 
차이가 가장 큰 두 구간을 구할 수 있다.

예제를 따로 생각했을 때 가장 도움이 됐다.

9
1 2 1 1 2 1 1 2 2

내가 짠 코드대로면 누적합에 의해 배열 ans가
1 0 1 2 1 2 3 2 1 이 될 테고,
min = 0, max = 3으로,
1 1 2 1 1 을 선택했을 때의 최대의 깨달음인 3이 출력된다.
*/