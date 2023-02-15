/*
https://www.acmicpc.net/problem/11286
백준 11286 절댓값 힙
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long heap[1000005];
long long sz = 0;

void push(long long x) {
    heap[++sz] = x;
    long long idx = sz;
    while(idx != 1) {
        long long par = idx / 2;
        if(abs(heap[par]) < abs(heap[idx])) break;
        else if(abs(heap[par]) > abs(heap[idx])) {
            swap(heap[par], heap[idx]);
            idx = par;
        }
        else if(abs(heap[par]) == abs(heap[idx]) && heap[par] > heap[idx]) {
            swap(heap[par], heap[idx]);
            idx = par;
        }
        else break;
    }
}
void top() {
    cout<<heap[1]<<'\n';
}
void pop() {
    if(sz == 0) {
        return;
    }
    heap[1] = heap[sz--];
    heap[sz +1] = 0;
    long long idx = 1;
    while(2 * idx <= sz) {
        long long lc = 2 * idx, rc = 2 * idx  + 1;
        long long min_child = lc;
        if(rc <= sz && abs(heap[rc]) < abs(heap[lc])) min_child = rc;
        if(rc <= sz && abs(heap[rc]) == abs(heap[lc]) && heap[rc] < heap[lc]) min_child = rc;
        if(abs(heap[idx]) < abs(heap[min_child])) break;
        if(abs(heap[idx]) == abs(heap[min_child]) && heap[idx] < heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n == 0) {
            top();
            pop();
        }
        else {
            push(n);
        }
    }
}

/*
풀이

push, pop, top을 바킹독 강의를 통해 배우고 풀었다.
+
주는 조건에 맞춰서 구현만 하면 된다.
*/