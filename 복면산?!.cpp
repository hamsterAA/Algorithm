/*
https://www.acmicpc.net/problem/15811
백준 15811 복면산?!
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2, s3;
int arr[100], word[100], word_num[100], fir, s1_len, s2_len, s3_len, printed;
bool isused[11];
void func(int k) {
    if(printed) return;
    if(k == fir) {
        long long add1 = 0, add2 = 0, add3 = 0;
        for(int i = 0; i < s1_len - 1; i++) {
            add1 += word_num[s1[i]];
            add1 *= 10;
        }
        add1 += word_num[s1[s1_len - 1]];
        
        for(int i = 0; i < s2_len - 1; i++) {
            add2 += word_num[s2[i]];
            add2 *= 10;
        }
        add2 += word_num[s2[s2_len - 1]];
        
        for(int i = 0; i < s3_len - 1; i++) {
            add3 += word_num[s3[i]];
            add3 *= 10;
        }
        add3 += word_num[s3[s3_len - 1]];
        
        if(add1 + add2 == add3) {
            printed = 1;
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        if(!isused[i]) {
            word_num[word[k]] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>s1;
    s1_len = s1.length();
    for(int j = 0; j < s1_len; j++) {
        if(!arr[s1[j]]) {
            arr[s1[j]]++;
            word[fir++] = s1[j];
        }
    }
    cin>>s2;
    s2_len = s2.length();
    for(int j = 0; j < s2_len; j++) {
        if(!arr[s2[j]]) {
            arr[s2[j]]++;
            word[fir++] = s2[j];
        }
    }
    cin>>s3;
    s3_len = s3.length();
    for(int j = 0; j < s3_len; j++) {
        if(!arr[s3[j]]) {
            arr[s3[j]]++;
            word[fir++] = s3[j];
        }
    }
    
    sort(word, word +fir);
    func(0);
    if(!printed) cout<<"NO";
    else cout<<"YES";
}
/*
풀이

브루트포스 + 백트래킹으로 푼다.
18자리 숫자까지 가능하니, long long 으로 숫자를 선언한다.

1. 어떤 알파벳이 쓰이는지 확인한다.
2. 쓰이는 알파벳에 0 ~ 9의 숫자를 할당해준다.
3. 각 문자열에서 해당하는 단어에 숫자를 넣어서 계산해준다.
*/