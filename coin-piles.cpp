#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; 
	while(t--){
		int a, b;
		cin >> a >> b;
		
		if((a+b)%3 == 0 && max(a,b)<=2*min(a,b)){
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}

/*

two piles 
a b

condition that no more moves can be performed : 
when either of the piles becomes 0.

so we need to pick in a way that no pile becomes zero, or in
other words we need to minimize the abs difference b/w them for every move!

so what I will do is basically just pick 1 coin from the smaller pile and 2 coins from the larger.

ok so this approach accounts for the winning scenarios, ie one of the piles having a single coin left and the other having 2, and the next move results in both getting converted to 0, now the other cases where we reach a situation where we loose like the case where we have only 1 coin left in both the piles or either of them getting zero without the other so no moves left but still coins left so that will take care of the NO cases

for the a > 2b case yes its surely a NO since we cant win in that case so ill simply take care of this in the start itself

ok so we can say it be a yes when a+b is divisible by 3 since mathematically we can say that if both the piles are converted to 0 in some x moves then the total number of coins must be 3*x . thus we can say that if the sum (a+b) is divisible by 3 and max(a,b)≤2×min(a,b) then teh answer will be yes, else it will be no

*/

