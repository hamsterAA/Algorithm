/*
https://www.acmicpc.net/problem/17609
백준 17609 회문
*/
#include <iostream>
#include <cstring>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        int l = s.length();
        bool passed = 0;
        int right = 1, ans = 0;
        for(int i = 0; i < l / 2; i++) {
            //cout<<s[i]<<' '<<s[l - right - i]<<'\n';
            if(s[i] != s[l - right - i] && !passed) {
                passed = 1;
                ans = 1;
                right++;
                i--;
            }
            else if(s[i] != s[l - right - i] && passed) {
                ans = 2;
            }
        }
        if(ans != 2) {
            cout<<ans<<'\n';
            continue;
        }
        passed = 0;
        int left = 0;
        for(int i = 0; i < l / 2; i++) {
            //cout<<s[i + left]<<' '<<s[l - 1 - i]<<'\n';
            if(s[i + left] != s[l - 1 - i] && !passed) {
                passed = 1;
                ans = 1;
                left++;
                i--;
            }
            else if(s[i + left] != s[l - 1 - i] && passed) {
                ans = 2;
            }
        }
        cout<<ans<<'\n';
    }
}

/*
풀이

투포인터로 앞, 뒤에서부터 하나씩 비교해간다.
왼쪽에서 하나 건너뛰고, 오른쪽에서 하나 건너뛰며 확인해서 output을 결정한다. 
*/