/*
https://www.acmicpc.net/problem/27377
백준 27377 읽씹 멈춰!
*/
#include<iostream>
using namespace std;
long long T,n, ans, t, s;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>n>>s>>t;
        long long ttemp = t / s;
        if(t % s) ttemp++;
        ans = s;
        if(n == 1) {
            cout<<ans<<'\n';
        }
        else {
            while(n != 2) {
                long long temp = n / 2;
                if(n % 2) {
                    ans += s;
                    n--;
                }
                else {
                    if(temp >= ttemp) {
                        ans += t;
                    }
                    else {
                        ans += s * temp;
                    }
                    n /= 2;
                }
            }
            if(s < t) cout<<ans + s<<'\n';
            else cout<<ans + t<<'\n';
        }
    }
}
/*
풀이

n에서부터 
홀수면, s
짝수인데 t / s <= n / 2 면, t
짝수인데 위와 다르다면, s * n / 2
를 더해주는 그리디한 문제였다.

하지만, s * n / 2가 long long의 범위를 벗어날 수 있어서 이에 신경써줘야했다.
*/