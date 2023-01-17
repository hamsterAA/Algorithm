/*
https://www.acmicpc.net/problem/15666
백준 15666 N과 M (12)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], ans[10], n, m, temp, coun;
bool isused[10001];

void func(int k) {
    if(k == m + 1) {
        for(int i = 1; i <= m; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 1; i <= coun; i++) {
        ans[k] = arr[i - 1];
        if(ans[k] < ans[k - 1]) continue;
        func(k + 1);
    }
}
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>temp;
        isused[temp] = 1;
    }
    for(int i = 0; i < 10001; i++) {
        if(isused[i]) {
            arr[coun++] = i;
        }
    }
    sort(arr, arr + coun);
    func(1);
}

/*
풀이

숫자 최대치가 1만이니까 어느 숫자가 입력되는지만 확인 후, 
그 숫자들로만 백트래킹을 돌려준다.
*/