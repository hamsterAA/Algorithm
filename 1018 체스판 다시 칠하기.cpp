/*
https://www.acmicpc.net/problem/1018
백준 1018 체스판 다시 칠하기
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s[50];

int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>s[i];
    }
    int coun, coun2, ans = 100;
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            coun2 = coun = 0;
            for(int k = 0; k < 8; k++) {
                for(int l = 0; l < 8; l++) {
                    if((k + i) % 2 == 0 && (l + j) % 2 == 0 && s[k + i][l + j] == 'B') coun++;
                    if((k + i) % 2 == 1 && (l + j) % 2 == 1 && s[k + i][l + j] == 'B') coun++;
                    if((k + i) % 2 == 1 && (l + j) % 2 == 0 && s[k + i][l + j] == 'W') coun++;
                    if((k + i) % 2 == 0 && (l + j) % 2 == 1 && s[k + i][l + j] == 'W') coun++;

                    if((k + i) % 2 == 0 && (l + j) % 2 == 0 && s[k + i][l + j] == 'W') coun2++;
                    if((k + i) % 2 == 1 && (l + j) % 2 == 1 && s[k + i][l + j] == 'W') coun2++;
                    if((k + i) % 2 == 1 && (l + j) % 2 == 0 && s[k + i][l + j] == 'B') coun2++;
                    if((k + i) % 2 == 0 && (l + j) % 2 == 1 && s[k + i][l + j] == 'B') coun2++; 
                }
            }
            ans = min({ans, coun, coun2});
        }
    }
    cout<<ans;
}
/*
풀이

N x M 크기의 보드에서 번갈아서 선택하는 방법만 알면 쉽게 풀 수 있다.
*/