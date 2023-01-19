/*
https://www.acmicpc.net/problem/1436
백준 1436 영화감독 숌
*/

#include <iostream>
using namespace std;

int n, ans, arr[10];

int main() {
    cin>>n;
    int end = 666;
    while(n) {
        int real_end = end++;

        int coun = 0;
        while(real_end) {
            arr[coun++] = real_end % 10;
            real_end /= 10;
        }
        
        for(int i = 0; i <= coun - 3; i++) {
            if(arr[i] == 6 && arr[i + 1] == 6 && arr[i + 2] == 6) {
                ans = end - 1;
                n--;
                break;
            }
        }

    }
    cout<<ans;
}

/*
풀이

완전탐색으로 구해준다.

*/