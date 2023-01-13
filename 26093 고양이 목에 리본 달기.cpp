/*
https://www.acmicpc.net/problem/26093
백준 26093 고양이 목에 리본 달기
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
unsigned long long arr[101][2][2];
vector<pair<long long, long long> > v;

int main() {
cin.tie(0);
cout.tie(0);
ios::sync_with_stdio(0);
long long n, m, temp;
cin>>n>>m;

//가장 큰 값, 그 위치와 두 번째로 큰 값 찾기
for(int j = 0; j < m; j++) {
    cin>>temp;
    v.push_back(pair<long long, long long>(temp, j));
}
sort(v.begin(),v.end());
arr[0][0][0] = v[m - 1].first;
arr[0][0][1] = v[m - 1].second;
arr[0][1][0] = v[m - 2].first;
v.clear();

//DP로 가장 큰 값 혹은 두 번째로 큰 값 더해주고
//다 더하면 다시 가장 큰 값, 위치와 두 번째로 큰 값 찾기
for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin>>temp;
        v.push_back(pair<long long, long long>(temp, j));
        if(v[j].second != arr[i - 1][0][1]) {
            v[j].first += arr[i - 1][0][0];
        }
        else {
            v[j].first +=arr[i - 1][1][0]; 
        }
    }
    sort(v.begin(), v.end());
    arr[i][0][0] = v[m - 1].first;
    arr[i][0][1] = v[m - 1].second;
    arr[i][1][0] = v[m - 2].first;
    v.clear();
}
cout<<arr[n - 1][0][0];
}

/*
풀이

모든 배열을 미리 입력받은 후, 가장 큰 값과 그 다음으로 큰 값 2가지만 갖고 계산하는 코드를 짰더니 93%에서 틀렸다.
한 줄씩 계산하고 그 중에 큰 값 2가지를 찾는 과정으로 풀었더니 AC를 받았다.

내가 풀었지만, 왜 첫 번째 풀이 방식이 틀렸는지는 아직도 확실치 않다.

나머지 풀이는 코드에 주석으로 섞어놓음
*/