/*
https://www.acmicpc.net/problem/1966
백준 1966 프린터 큐
*/

#include <iostream>
#include <queue>
using namespace std;
queue <int> Q;
int big, arr[10];

void BIG() {
    for(int i = 9; i > 0; i--) {
        if(arr[i]) {
            big = i;
            return;
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int coun = 0;
        for(int i = 1; i < 10; i++) arr[i] = 0; 
        int n, m, tem; cin>>n>>m;
        Q = queue<int>(); //초기화
        while(n--) {
            cin>>tem;
            arr[tem]++;
            Q.push(tem);
        }
        BIG();
        while(1) {
            int front = Q.front(); Q.pop();
            
            if(!arr[big]) BIG();

            if(big <= front) {
                coun++;
                arr[front]--;
                if(m == 0) {
                    cout<<coun<<'\n';
                    break;
                }
            }
            else Q.push(front);
            
            if(m == 0) m = Q.size();
            m--;
        }
    }
}

/*
풀이

자료구조의 사용에 미숙해서 실버 문제이지만 여러번 틀렸다.

테스트 케이스가 여러번 들어오는데,
큐를 사용하고 비우는 과정을 생략했더니 WA와 TLE가 발생했다.

while(!Q.empty()) 를 사용하지 않은 이상,
큐를 초기화해줘야 한다는 것에 유의해야겠다.
*/