#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 1 << n; // 2^n Gray codes

    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);

        for (int j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1);
        }
        cout << "\n";
    }

    return 0;
}


/*
for 1 : 
0 -> 1

for 2 :
00 -> 01 -> 11 -> 10

for 3 : 
000 -> 001 -> 011 -> 010 -> 110 -> 111 -> 101 -> 100
*/