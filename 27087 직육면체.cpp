/*
https://www.acmicpc.net/problem/27087
백준 27087 직육면체
*/

#include <iostream>
using namespace std;
int t, a,b,c,p,d;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--) {
        d = 0;
        cin>>a>>b>>c>>p;
        if(!(a % p)) d++;
        if(!(b % p)) d++;
        if(!(c % p)) d++;
        if(d > 1) cout<<1;
        else cout<<0;
        cout<<'\n';
    }
}

/*
풀이

직관적으로 2개의 면이 p의 배수가 아니라면 채울 수 없을 것 같다는 느낌이 들었다.
*/