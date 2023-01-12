/*
https://www.acmicpc.net/problem/1038
백준 1038 감소하는 수
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, coun = 9;
long long arr[5000] = {1,2,3,4,5,6,7,8,9};
void func(int k) {
    if(k == n || coun >= n) {
        cout<<arr[n - 1];
        return;
    }
    for(int i = 0; i <= 9; i++) {
        if(arr[k] % 10 <= i) break;
        arr[coun] = arr[k] * 10 + i;
        coun++;
    }
    func(k + 1);
} 
int main() {
    cin>>n;
    if(n == 0) {
        cout<<0;
        return 0;
    }
    else if(n > 1022) {cout<<-1; return 0;}
    func(0);
}
/*
풀이

1 2 3 ~ 9 차례대로 배열에 넣어놓고
뒷자리에 0부터 1씩 올려보면서 넣는다.
맨 뒷자리 숫자가 앞자리 숫자와 같아지면 break,
앞자리 숫자보다 작다면 arr에 넣는다.
=>
배열에 들어간 숫자들을 전부 확인한 후, 갯수 확인 후 그 이상 input 들어오면 -1
*/