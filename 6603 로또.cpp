/*
https://www.acmicpc.net/problem/6603
백준 6603 로또
*/

#include <iostream>
using namespace std;
int arr[15], ans[15], n, isused[15];
void func(int k) {
    if(k == 7) {
        for(int i = 1; i <= 6; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            ans[k] = arr[i];
            if(ans[k] < ans[k - 1]) continue;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}
int main() {
    do {
        cin>>n;
        for(int i = 0; i < n; i++) cin>>arr[i];
        func(1);
        cout<<'\n';
    } while(n);
}

/*
풀이

백트래킹 연습 겸 풀었다.

전형적인 오름차순 백트래킹 문제이다.
항상 6개를 고른다는 점이 그나마 다른 점이다.
*/