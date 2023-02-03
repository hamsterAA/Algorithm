/*
https://www.acmicpc.net/problem/14891
백준 14891 톱니바퀴
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10][10],check[5],how[5], n, score;
string a;

void spin(int k, int z) {
    if(z == 1) {
        for(int i = 8; i >= 1; i--) {
            arr[i + 1][k] = arr[i][k]; 
        }
        arr[1][k] = arr[9][k];
    }
    else if (z == -1) {
        for(int i = 1; i <= 8; i++) {
            arr[i - 1][k] = arr[i][k];
        }
        arr[8][k] = arr[0][k];
    }
    return;
}

int main() {
    for(int i = 1; i <= 4; i++) {
        cin>>a;
        for(int j = 1; j <= 8; j++) {
            arr[j][i] = a[j - 1] - 48;
        }
    }  
    cin>>n;
    while(n--) {
        int wheel, s; cin>>wheel>>s;
        int tmp = wheel, d = s;
        while(1) {
            check[tmp] = 1;
            how[tmp] = d;
            d *= -1;
            tmp++;
            if(tmp == 5) break;
            if(arr[7][tmp] == arr[3][tmp - 1]) break;
        }
        tmp = wheel; d = s;
        while(1) {
            check[tmp] = 1;
            how[tmp] = d;
            d *= -1;
            tmp--;
            if(tmp == 0) break;
            if(arr[3][tmp] == arr[7][tmp + 1]) break;
        }

        for(int i = 1; i <= 4; i++) {
            spin(i, how[i]);
            check[i] = 0;
            how[i] = 0;
        }
    }
    int O = 1;
    for(int i = 1; i <= 4; i++, O *= 2) {
        if(arr[1][i]) score += O;
    }
    cout<<score;
}
/*
풀이

돌릴 톱니바퀴가 있는지 확인하고, 마지막에 전부 돌려준다.
돌릴 톱니바퀴를 확인하는 과정이 많이 헷갈렸다.

톱니바퀴가 4개 뿐이라 돌아가는 경우의 수가 별로 없어,
그냥 모든 상황을 구현해도 문제는 없었지만,
톱니바퀴가 하나만 늘어났어도 많이 귀찮았을 것이다.

*/