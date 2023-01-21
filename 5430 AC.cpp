/*
https://www.acmicpc.net/problem/5430
백준 5430 AC
*/
#include <iostream>
#include <cstring>
using namespace std;

int t, n;
string s, inp;
int arr[300001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>s;
        cin>>n;
        cin>>inp;
        int str_length = s.length();
        int input_length = inp.length();
        int coun = 0;

        for(int i = 1; i < input_length - 1; i++) {
            if(inp[i] != ',') {
                if(inp[i - 1] != ',' && inp[i - 1] != '[') {
                    coun--;
                    arr[coun] *= 10;
                    
                }
                arr[coun] += inp[i] - 48;
                //cout<<arr[coun] << '\n';
                coun++;
            }
        }

        int start = 0, end = n, reverse = 0;
        for(int i = 0; i < str_length; i++) {
            if(s[i] == 'R' && reverse == 0) {
                reverse = 1;
            }
            else if(s[i] == 'R' && reverse == 1) {
                reverse = 0;
            }
            else if(s[i] == 'D' && reverse == 0) {
                start++;
            }
            else {
                end--;
            }
        }

        if(start > end) {
            cout<<"error"<<'\n';
        }
        else if(start == end) {
            cout<<"[]"<<'\n';
        }
        else {
            if(!reverse) {
                cout<<'[';
                for(int i = start; i < end - 1; i++) {
                    cout<<arr[i]<<',';
                }
                cout<<arr[end - 1];
                cout<<']'<<'\n';
            }
            else {
                cout<<'[';
                for(int i = end - 1; i > start; i--) {
                    cout<<arr[i]<<',';
                }
                cout<<arr[start];
                cout<<']'<<'\n';
            }
        }
        for(int i = 0; i < coun; i++) {
            arr[i] = 0;
        }
    }
}

/*
풀이
그냥 단순하게,
1. [x1,...,xn]과 같은 형태로 배열에 들어있는 정수에서 정수만 뺀다.
2. R이 활성화 돼있으면 끝나는 지점을, 아니라면 시작 지점을 앞당겨준다.
3. 형식에 맞게 출력한다. 
이게 전부이다.
주의해야 할 점은, 
1. []의 빈 배열이 발생했을 때 [0]을 출력하지 않도록 사이드케이스의 출력에 유의.
2. 처음 입력받은 문자열 형태의 배열에서 정수를 뺄 때 한 자리 수가 아닌, 두, 세자리 수의 숫자도 들어갈 수 있기에 유의.
이다.

*/