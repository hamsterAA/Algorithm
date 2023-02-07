/*
https://www.acmicpc.net/problem/25125
백준 25215 타이핑
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string s;
int func(int i) {
    if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') return 1;
    else if (s[i] >= 'A' && s[i] <= 'Z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') return 2;
    else if(s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') return 3;
    else if(s[i] >= 'A' && s[i] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') return 4;
    else return 0;
} 
int main() {
    cin>>s;
    int len = s.length(), sq = 0, coun = 0;
    for(int i = 0; i < len - 1; i++) {
        if(!sq && func(i) == 2) {
            coun += 2; 
        }
        else if(sq && func(i) == 1) {
            coun += 2;
        }
        else if(sq && func(i) == 3) {
            sq = 0;
            coun += 2;
        }
        else if(!sq && func(i) == 4) {
            sq = 1;
            coun += 2;
        }
        else coun++;
    }
    if(sq && s[len - 1] >= 'a' && s[len - 1] <= 'z') coun+=2;
    else if(!sq && s[len - 1] >= 'A' && s[len - 1] <= 'Z') coun+=2;
    else coun++;
    cout<<coun;
}
/*
풀이

캡스록이 켜져있을 때와 꺼져있을 때를 나눠서 생각한다.
*/