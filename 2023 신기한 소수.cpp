/*
https://www.acmicpc.net/problem/2023
백준 2023 신기한 소수
*/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int dx[4] = {1,3,7, 9};
int n, ans;
queue <int> Q;

void Prime() {
    int size = Q.size();
    while(size--){
        for(int i = 0; i < 4; i++) {
            bool isPrime = 1;
            int cur = Q.front() * 10 + dx[i];

            for(int j = 3; j <= sqrt(cur); j++) {
                if(cur % j == 0){ 
                isPrime = 0;
                break;
                }
            }
            if(isPrime) {
                Q.push(cur);
            }
        }
        Q.pop();
    }
}

int main() {
    Q.push(2);
    Q.push(3);
    Q.push(5);
    Q.push(7);
    cin>>n;

    for(int i = 1; i < n; i++) {
        Prime();
    }
    
    ans = Q.size();
    for(int i = 0; i < ans; i++) {
        cout<<Q.front()<<'\n';
        Q.pop();
    }
}

/*
풀이

백트래킹이 딱히 떠오르지 않아 그냥 풀었다.
메모리 제한이 작으며, 8자리 수까지 판별하는 문제라 에라토스테네스의 체를 사용할 수는 없다.

내가 푼 방법은

1. 큐에 담긴 n자리 소수의 뒷자리에 1,3,7,9를 넣어서 n + 1자리의 숫자를 만든다.
2. 소수판별하여 소수인 것들만 큐에 담는다.
3. 소수가 아닌 것들은 pop.
*/