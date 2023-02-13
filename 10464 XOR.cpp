/*
https://www.acmicpc.net/problem/10464
백준 10464 XOR
*/

#include <iostream>
using namespace std;

int Xor(int n) {
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
}

int main() {
    int t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        n = Xor(n - 1) ^ Xor(m);
        cout<<n<<'\n';
    }
}

/*
풀이

1 부터 n까지의 xor을 구하는 법은 쉽다.

(xor(1 to n-1) ⊕ xor(1 to m)) = xor(n to m) 인 이유는, 
let's consider the case where n = 5 (101 in binary) and m = 6 (110 in binary). 
The XOR of the numbers from n to m is equal to XOR(101, 110), which is 011 in binary. 

However, the XOR of the numbers from 1 to n-1 is equal to XOR(1, 2, 3, 4),
and the XOR of the numbers from 1 to m is equal to XOR(1, 2, 3, 4, 5, 6). 

By XORing these two ranges, we effectively eliminate the duplicates (1, 2, 3, 4) and arrive at the XOR of the numbers from n to m:
XOR(XOR(1, 2, 3, 4), XOR(1, 2, 3, 4, 5, 6)) = XOR(101, 110) = 011.

중복된 것들이 제거되기 때문에 이게 성립한다.
*/