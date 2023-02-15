/*
https://www.acmicpc.net/problem/11000
백준 11000 강의실 배정
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, ans;
struct a {
    int start;
    int end;
};
struct cmp {
    bool operator()(a t, a u) {
        return t.end > u.end;
    }
};
bool vecmp(a x, a y) {
    if(x.start != y.start) {
    return x.start < y.start;
    }
    else return x.end > y.end;
}
priority_queue<a, vector<a>, cmp> pq;
vector<a> vec;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    struct a b;
    for(int i = 0; i < n; i++) {
        cin>>b.start>>b.end;
        vec.push_back(b);
    }
    sort(vec.begin(), vec.end(), vecmp);
    

    for(int i = 0; i < n; i++) {
        while(!pq.empty()) {
            int t = vec[i].start;
            if(pq.top().end > vec[i].start) break;
            pq.pop();
        }
        pq.push(vec[i]);
        int tmp = pq.size();
        ans = max(ans, tmp);
    }
    cout<<ans;
    
}
/*
풀이

1. 일찍 시작하는 순서대로 먼저 강의를 정렬한다.
2. 끝나는 시간 기준으로 정렬한 우선순위 큐에 새로운 강의를 하나씩 넣는다.
3. 새로 들어온 강의의 시작시간이 다른 강의의 끝나는 시간보다 빠르면 큐에서 pop
4. 큐의 사이즈를 체크하며 최대 강의 수를 확인
*/