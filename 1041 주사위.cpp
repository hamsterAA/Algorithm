/*
https://www.acmicpc.net/problem/1041
백준 1041 주사위
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long one, two, three = 200, sum;
long long arr[10], n;


int main() {
    cin>>n;
    for(int i = 0; i < 6; i++) {
        cin>>arr[i];
    }

    if(n == 1) {
        sort(arr, arr + 6);
        sum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
    }
    else {
        arr[0] = min(arr[0] , arr[5]);
        arr[1] = min(arr[1] , arr[4]);
        arr[2] = min(arr[2] , arr[3]);

        sort(arr, arr + 3);
        one = arr[0];
        two = one + arr[1];
        three = two + arr[2];
        sum += three * 4;
        sum += (two) * ((4 * n - 4) + (4 * n - 8) ) ;
        sum += (one) * ((n - 2) * (n - 2) + (4) * (n - 1) * (n - 2));
    }
    cout<<sum;
}

/*
풀이

1. 3개의 면, 2개의 면의 합이 최소가 되는 경우를 찾는다.
2. n^3 모양으로 쌓은 주사위에서 각각의 면이 몇개나 생기는지 계산한다.
3. 곱해서 출력한다.

n = 1인 경우에 유의한다.
*/