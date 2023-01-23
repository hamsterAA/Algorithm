/*
https://www.acmicpc.net/problem/15686
백준 15686 치킨 배달
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[51][51], n, m, chicken;
int all_chicken[15][3], ans[15];
int all_house[101][3], house;
int temp_ans[101], result, minn = 10000000;

void func(int k) {
    if(k == m + 1) {
        for(int i = 0; i < house; i++) {
            result = 0;
            temp_ans[i] = 1500;
            for(int j = 1; j<= m; j++) {
                temp_ans[i] = min(temp_ans[i], abs(all_chicken[ans[j]][1] - all_house[i][1]) +  abs(all_chicken[ans[j]][2] - all_house[i][2]));
            }
        }
        for(int i = 0; i < house; i++) {
            result += temp_ans[i];
        }
        minn = min(result, minn);
        return;
    }
    for(int i = 0; i < chicken; i++) {
        if(!all_chicken[i][0]){
            ans[k] = i;
            all_chicken[i][0] = 1;
            func(k + 1);
            all_chicken[i][0] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 1) {
                all_house[house][1] = i;
                all_house[house][2] = j;
                house++;
            }
            else if(arr[i][j] == 2) {
                all_chicken[chicken][1] = i;
                all_chicken[chicken][2] = j;
                chicken++;
            }
        }
    }
    func(1);
    cout<<minn<<'\n';
}

/*
풀이

1. 모든 치킨집 중 m개를 고르는(치킨집 C m) 백트래킹을 구현한다. 나는 여기서 실수가 있었다.
2. m개의 치킨집에서 집과의 거리를 구한다.
3. 위의 과정을 (치킨집 C m)번 반복해서 최솟값을 출력한다.

*/