#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    
    vector<int> freq(26,0);
    
    for(int i=0 ; i<n ; i++) freq[s[i] -  'A']++;

    bool flag = false;
    for(int n : freq){
    	if(n&1){
	    if(flag){
	    	cout <<  "NO SOLUTION" << "\n";
		return 0;
	    } else {
		flag = true;
	    }
	}
    }

    string res = "";

    for(int i=0 ; i<26 ; i++){
	if(freq[i]&1) continue;
	for(int j=1 ; j<=freq[i]/2 ; j++){
	    res+=('A' + i);
	}
    }

    for(int i=0 ; i< 26 ; i++){
	if(freq[i]&1){
	    for(int j=1 ; j<=freq[i] ; j++){
	    	res+=(i+'A');
	    }
    	}
    }

    for(int i=25 ; i>=0 ; i--){
	if(freq[i]&1) continue;
	for(int j=1 ; j<=freq[i]/2 ; j++){
	    res+=('A' + i);
	}
    }

    cout << res << "\n";
    return 0;
}