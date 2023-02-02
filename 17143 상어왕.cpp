/*
https://www.acmicpc.net/problem/17143
백준 17143 상어왕
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
    int R, C, S, D, Z;
};
vector <Shark> shark[101][101];
vector <Shark> temp_map[101][101];
int dy[5] = {0, -1, 1, 0, 0}, dx[5] = {0, 0, 0, 1, -1}, r, c, m;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>r>>c>>m;
    for(int i = 0; i < m; i++) {
        Shark t;
        cin>>t.R>>t.C>>t.S>>t.D>>t.Z;
        if(t.D == 1 || t.D == 2) t.S %= (r - 1) * 2;
        else t.S %= (c - 1) * 2;
        shark[t.R][t.C].push_back(t);
    }
    int temp_c = c, king = 0, score = 0;
    while(temp_c--) {
        king++;
        for(int i = 1; i <= r; i++) {
            if(!shark[i][king].empty()) {//상어 잡기
                score += shark[i][king][0].Z;
                shark[i][king].pop_back();
                break;
            }
        }
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(shark[i][j].empty()) continue; //상어 이동
                Shark t = shark[i][j].back();
                shark[i][j].pop_back();
                int temp_s = t.S;
                if(t.D == 1 || t.D == 2) {
                    while(temp_s--) {
                        if(t.R == 1) t.D = 2;
                        else if(t.R == r) t.D = 1;
                        t.R += dy[t.D];
                    }
                }
                else {
                    while(temp_s--) {
                        if(t.C == 1) t.D = 3;
                        else if(t.C == c) t.D = 4; 
                        t.C += dx[t.D];
                    }
                }

                if(!temp_map[t.R][t.C].empty()) { //큰 거 하나만
                    if(temp_map[t.R][t.C][0].Z < t.Z) {
                        temp_map[t.R][t.C].pop_back();
                        temp_map[t.R][t.C].push_back(t);
                    }
                }
                else {
                    temp_map[t.R][t.C].push_back(t);
                }
            }
        }
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                shark[i][j] = temp_map[i][j];
                if(!temp_map[i][j].empty()) temp_map[i][j].pop_back();
            }
        }
    }
    cout<<score;
}

/*
풀이

순서대로,
1. 낚시왕을 옮기고, 같은 열의 상어를 잡는다.
2. 상어를 옮기고, 임시로 저장한다.
3. 옮긴 상어의 위치에 다른 상어가 있다면, 큰 상어만 남긴다.
4. 이동이 끝나면, 임시로 저장한 상어 전부를 업데이트한다.

위의 과정을 c번 반복한다.

처음으로 struct를 사용해서 풀었다.
vector와 struct 사용하는 습관을 들여야 구현 문제를 쉽게 풀듯하다.
*/