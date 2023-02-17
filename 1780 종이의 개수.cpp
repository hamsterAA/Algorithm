/*
https://www.acmicpc.net/problem/1780
백준 1780 종이의 개수
*/

#include <iostream>
using namespace std;
int OO, ZZ, MM;
int arr[2188][2188];
void rec(int x, int y, int N) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            bool O = 0, Z = 0, M = 0;
            for(int k = x + (i * N); k < x + (N * (i + 1)); k++) {
                for(int l = y + (j * N); l < y + (N * (j + 1)); l++) {
                    if(arr[k][l] == 1) O = 1;
                    else if(arr[k][l] == 0) Z = 1;
                    else M = 1;
                }
            }
            if(O + Z + M > 1) {
                rec(x + (i * N), y + (j * N), N / 3);
            }
            else {
                if(O) OO++;
                else if(Z) ZZ++;
                else MM++;
            }
        }
    }
}
int main() {
    int n;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    bool o = 0, z = 0, m = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 0) z = 1;
            else if(arr[i][j] == 1) o = 1;
            else m = 1;
        }
    }
    if(o + z + m > 1) rec(0, 0, n / 3);
    else {
        MM = m;
        OO = o;
        ZZ = z;
    }
    cout<<MM<<'\n'<<ZZ<<'\n'<<OO<<'\n';
}

/*
풀이

재귀적으로 현재 종이에 같은 수만 있지 않다면,
9등분 하여 다시 탐색하도록 작성한다.
*/