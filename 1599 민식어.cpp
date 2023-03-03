/*
https://www.acmicpc.net/problem/1599
백준 1599 민식어
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
string s[50], num[50], ans[50];
map<char, string> m;
map<char, string> an;
int main() {
    m.insert(make_pair('a', "a"));
    m.insert(make_pair('b', "b"));
    m.insert(make_pair('k', "c"));
    m.insert(make_pair('d', "d"));
    m.insert(make_pair('e', "e"));
    m.insert(make_pair('g', "f"));
    m.insert(make_pair('h', "g"));
    m.insert(make_pair('i', "h"));
    m.insert(make_pair('l', "i"));
    m.insert(make_pair('m', "j"));
    m.insert(make_pair('n', "k"));
    m.insert(make_pair('o', "m"));
    m.insert(make_pair('p', "n"));
    m.insert(make_pair('r', "o"));
    m.insert(make_pair('s', "p"));
    m.insert(make_pair('t', "q"));
    m.insert(make_pair('u', "r"));
    m.insert(make_pair('w', "s"));
    m.insert(make_pair('y', "t"));
    an.insert(make_pair('a', "a"));
    an.insert(make_pair('b', "b"));
    an.insert(make_pair('c', "k"));
    an.insert(make_pair('d', "d"));
    an.insert(make_pair('e', "e"));
    an.insert(make_pair('f', "g"));
    an.insert(make_pair('g', "h"));
    an.insert(make_pair('h', "i"));
    an.insert(make_pair('i', "l"));
    an.insert(make_pair('j', "m"));
    an.insert(make_pair('k', "n"));
    an.insert(make_pair('m', "o"));
    an.insert(make_pair('n', "p"));
    an.insert(make_pair('o', "r"));
    an.insert(make_pair('p', "s"));
    an.insert(make_pair('q', "t"));
    an.insert(make_pair('r', "u"));
    an.insert(make_pair('s', "w"));
    an.insert(make_pair('t', "y"));
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s[i];
        for(int j = 0; j < s[i].length(); j++) {
            if(s[i][j] == 'n' && j + 1 < s[i].length() && s[i][j + 1] == 'g') {
                num[i] += "l";
                j++;
            }
            else num[i] += m[s[i][j]];
        }
    }
    sort(num, num + n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < num[i].length(); j++) {
            if(num[i][j] == 'l') ans[i] += "ng";
            else ans[i] += an[num[i][j]];
        }
    }
    for(int i = 0; i < n; i++) cout<<ans[i]<<'\n';
}

/*
풀이

모든 알파벳을 숫자로 바꿔서 계산하려다가, 10이 넘는다는 것을 알고 알파벳으로 각각 매칭 시켜줬다.
각각 대응하는 알파벳으로 변환 후,
정렬한 후에,
대응하는 알파벳으로 원래의 문자열을 완성한다.
*/