/*
https://www.acmicpc.net/problem/24525
백준 24525 SKK 문자열
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[100010] = {100000};
int brr[300010];
int crr[100010];
string s, temp, ex;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin>>temp;
    s = " " + temp;
    int length = s.length();
    int scheck = 0, kcheck = 0;
    for(int i = 0; i < length; i++) {
        if(s[i] == 'S') {
            ex += 'S';
            scheck = 1;
            arr[i + 1] = arr[i] + 2;
        }
        else if(s[i] == 'K') {
            ex += 'K';
            kcheck++;
            arr[i + 1] = arr[i] - 1;  
        }
        else arr[i + 1] = arr[i];
    }
    int mx = 0;
    for(int i = 1; i <= length; i++) {
        if(brr[arr[i]] == 0) {
            brr[arr[i]] = i;
        }
        else {
            crr[i] = i - brr[arr[i]];
            mx = max(crr[i], mx);
        }
    }
    bool avil = 0;
    ex+="  ";
    int ex_length = ex.length();
    for(int i = 1; i <= ex_length; i++) {
        if(ex[i] == 'S') {
            if(ex[i - 1] =='K' && ex[i + 1] =='K') {
                avil = 1;
            }
            if(ex[i - 1] == 'K' && ex[i - 2] =='K') {
                avil = 1;
            }
            if(ex[i + 1] == 'K' && ex[i + 2] =='K') {
                avil = 1;
            }
        }
        if(avil) break;
    }
    if(!avil || mx == 0 || scheck == 0 || kcheck < 2) cout<<-1;
    else cout<<mx;
}

/*
풀이
누적합으로 배열에 S는 +2, K는 -1로 계산한다.
만약 누적합에서 배열에서 여태 등장한 숫자가 재등장하면,
그 사이 구간의 누적합은 0임을 알 수 있다.
ex) SSSAAAKK => 24666654 => 앞의 SS를 자르면 SAAAKK => 222210 으로 누적합은 0이다.
따라서 동일한 숫자가 늦게 나올 수록 SKK 문자열의 길이는 길어진다.

SKK 문자열이 유효한지 검사하기 위해서
S 앞뒤로 K가 2개 등장하는지,
S와 K의 최소 개수를 충족하는지 확인해줘야한다.
*/