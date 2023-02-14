/*
https://www.acmicpc.net/problem/1790
백준 1790 수 이어 쓰기 2
*/

#include <iostream>
using namespace std;
int main() {
    long long aa = 0, n,k,temp = 9, l = 1;
    cin>>n>>k;
    while(k > 0) {
        k -= temp * l;
        aa += temp;
        temp *= 10;
        l++;
    }
    temp /= 10;
    k += temp * --l;
    aa -= temp;
    long long num = (k + l - 1)/ l, mod = (k + l - 1) % l;    
    long long m = aa + num;
    if(m > n) cout<<-1;
    else {
        for(long long i = 0; i < l - mod - 1; i++) {
            m /= 10;
        }
        cout<<m % 10;
    }
}
/*
풀이

1 ~ 9는 9개
10 ~ 99는 90개
...
라는 점을 기반으로 구현해서 푼다.

이런 류의 수학적인 구현력이 많이 부족하다고 느꼈다.

병원에서 피 뽑으면서 풀어서 집중하지 못했다. 
결과적으로 오래 걸렸다.
*/