#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> indexes;
        indexes.push_back(-1);
        for (int i = 0; i < n; i++)
            if (s[i] == '1') indexes.push_back(i);

        if (indexes.size() == 1) {
            cout << (n + k) / (k + 1) << '\n';
            continue;
        }

        indexes.push_back(n);

        long long ans = 0;
        for (size_t i = 1; i < indexes.size(); i++) {
            int left = indexes[i - 1];
            int right = indexes[i];
            int x = right - left - 1;

            if (left == -1 || right == n) {
                ans += x / (k + 1);     
            } else {
                ans += (x - k) / (k + 1); 
            }
        }

        cout << ans << '\n';
    }

    return 0;
}