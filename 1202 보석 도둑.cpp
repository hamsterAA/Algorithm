/*
https://www.acmicpc.net/problem/1202
백준 1202 보석 도둑
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, m, t, c;
priority_queue <int> pq;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector < pair<int, int> > v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i].first>>v[i].second;
    }
    vector<int> y(k);
    for(int i = 0; i < k; i++) {
        cin>>y[i];
    }
    sort(y.begin(), y.end());
    sort(v.begin(), v.end());
    long long idx = 0, sum = 0;
    for(int i = 0; i < k; i++) {
        while(idx < n && v[idx].first <= y[i]) {
            pq.push(v[idx++].second);
        }
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout<<sum;
}

/*
풀이

우선순위 큐 + 그리디로 푼다.

milk scheduling 과 비슷하다
*/