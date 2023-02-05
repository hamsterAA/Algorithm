/*
https://www.acmicpc.net/problem/25166
백준 25166 배고픈 아리의 샌드위치 구매하기
*/
#include <iostream>
using namespace std;
int ans[11], arr[10],s,m;
int isused[10], money, flag = 0, coin, temp;
void func(int k) {
    if(k == temp) {
        money = 0;
        for(int i = 1; i < temp; i++) {
            money += ans[i];
        }
        //cout<<money<<' ';
        if(money == s) {
            flag = 1;
        }
        return;
    }
    for(int i = 0; i < coin; i++) {
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
    cin>>s>>m;
    s -= 1023;
    if(s <= 0) {
        cout<<"No thanks";
        return 0;
    }
    
    for(int i = 0, j = 512; i < 10; i++, j /= 2) {
        if(m >= j) {
            arr[coin++] = j;
            m -= j;
        }
    }
    for(int i = 1; i <= coin; i++) {
        temp = i + 1;
        func(1);
        if(flag) break;
    }

    if(flag) cout<<"Thanks";
    else cout<<"Impossible";
    
}

/*
풀이

브루트포스로 풀었다 하...
비트마스킹을 모른다.
*/