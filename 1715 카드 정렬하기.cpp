/*
https://www.acmicpc.net/problem/1715
백준 1715 카드 정렬하기
*/

#include <iostream>
#include <queue>
using namespace std;
long long arr[100001], n;
priority_queue<int, vector<int>, greater<int> > PQ;
long long a = 0, t;
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>t;
        PQ.push(t);
    }
    while(PQ.size() > 1) {
        int fir = PQ.top(); PQ.pop();
        int sec = PQ.top(); PQ.pop();
        a += fir + sec;
        PQ.push(fir + sec);
    }
    cout<<a;
}

/*
풀이

그리디하게 푼다.

가장 벌 수가 적은 카드 두 벌을 선택하여 섞으면 최소의 비교만 일어난다.
*/