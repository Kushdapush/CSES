#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> set1, set2;
    long long target = sum / 2;

    for (int i = n; i >= 1; --i) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << "YES\n";
    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n" << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}
