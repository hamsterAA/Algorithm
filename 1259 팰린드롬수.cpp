/*
https://www.acmicpc.net/problem/1259
백준 1259 팰린드롬수
*/
#include <iostream>
using namespace std;
int n, c;
int arr[6];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        c = 0;
        cin>>n;
        if(!n) return 0;
        bool check = 1;
        int start = 0;
        while(n) {
            arr[c++] = n % 10;
            n /= 10;   
        }
        c--;
        while(c) {
            if(arr[start] != arr[c]) {
                check = 0;
            }
            start++; c--;
        }
        if(check) cout<<"yes\n";
        else cout<<"no\n";
    }
}

/*
풀이

각 자릿수를 배열에 저장 후, 앞과 뒤에서부터 차례대로 비교 (투 포인터 처럼)
*/