#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int cnt = 1, max_cnt = 0;
    
    for(int i=0 ; i<s.size()-1 ;  i++){
        if(s[i] == s[i+1]){
            cnt++;
        } else {
            max_cnt = max(cnt, max_cnt);
            cnt = 1;
        }
    }
    max_cnt = max(cnt, max_cnt);
    
    cout <<  max_cnt;
    
    return 0;
}