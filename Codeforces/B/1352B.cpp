#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;

        bool samParity = (n % 2 == k % 2);

        if (samParity && n >= k) {
            cout << "Yes\n";
            for (int i = 0; i < k - 1; i++) cout << 1 << " ";
            cout << 1 + (n - k) << "\n";
        } else if (n % 2 == 0 && n >= 2 * k) {
            cout << "Yes\n";
            for (int i = 0; i < k - 1; i++) cout << 2 << " ";
            cout << (n - 2 * k + 2) << "\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}