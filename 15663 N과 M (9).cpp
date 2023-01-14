/*
https://www.acmicpc.net/problem/15663
백준 15663 N과 M (9)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], brr[10], n, m;
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout<<brr[i]<<' ';
    cout<<'\n';
    return;
    }
    int temp = -1;
    for(int i = 0; i < n; i++) {
        if(!isused[i] && temp != arr[i]) {
            brr[k] = arr[i];
            isused[i] = 1;
            temp = arr[i];
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr+n);
    func(0);
}
/*
풀이

func 내부에 temp를 초기화하면서 줘서 함수를 돌려준다.
예제
4 2
1 7 9 9 의 경우,
func(0) temp = 1 => func(1) temp = 7 => func(2) 출력
=> func(1) temp = 9 => func(2) 출력
=> func(1) temp = 9 중복

func(0) temp = 7 => func(1) temp = 1 => func(2) 출력
=> func(1) temp = 9 => func(2) 출력
=> func(1) temp = 9 중복

func(0) temp = 9 = > func(1) temp = 1 => func(2) 출력
=> func(1) temp = 7 => func(2) 출력
=> func(1) temp = 9 => func(2) 출력

func(0) = temp = 9 중복

이와 같이 작동한다.
*/
