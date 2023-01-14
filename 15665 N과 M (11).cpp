/*
https://www.acmicpc.net/problem/15665
백준 15665 N과 M (11)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,arr[10], ans[10];

void func(int k) {
    if(k == m + 1) {
        for(int i = 1; i <= m; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(temp != arr[i]) {
            ans[k] = arr[i];
            temp = arr[i];
            func(k + 1);
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    func(1);
}
/*
풀이

백트래킹 과정에서 함수마다 초기화되는 temp 값과 arr[i] 를 비교해서
공통된 값을 가진 부모 노드를 두 번 선택하지 않는 식으로 짜준다.

ex) 
input
3 2
1 1 9

func(1) temp = 1 => func(2) temp = 1 => func(3) 출력

(func(2)의 temp의 값이 1로, (1,1)을 한 번 더 출력하는 과정은 건너뛰어짐.)
func(2) temp = 9 => func(3) 출력

func(2) => func(1) temp = 1 (이 temp 값은 arr[0]의 값으로, arr[1]의 값과 일치하므로 if문에서 걸러진다.)
func(1) temp = 9 => func(2) temp = 1 => func(3) 출력

(func(2) temp 값이 1로, (9,1)을 한 번 더 출력하는 과정은 건너뛰어짐.)
func(2) temp = 9 => func(3) 출력
*/