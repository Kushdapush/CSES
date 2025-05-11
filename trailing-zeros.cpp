#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int ans = 0;
	int divisor = 5;

	while(n >= divisor){
		ans += n/divisor;
		divisor*=5;
	}

	cout << ans  << "\n";
	return 0;

}