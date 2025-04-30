#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] > m + 1) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l + 1 << "\n";

    return 0;
}
