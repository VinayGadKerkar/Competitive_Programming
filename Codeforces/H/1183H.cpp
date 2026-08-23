#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<long long>> dp(26, vector<long long>(n + 1, 0));
    vector<long long> total(n + 1, 0);

    for (char ch : s) {
        int c = ch - 'a';

        vector<long long> oldTotal = total;
        vector<long long> newValues(n + 1, 0);

        newValues[1] = 1;
        for (int len = 2; len <= n; len++)
            newValues[len] = oldTotal[len - 1];

        for (int len = 1; len <= n; len++) {
            total[len] -= dp[c][len];
        }

        for (int len = 1; len <= n; len++) {
            dp[c][len] = min(k, newValues[len]);
            total[len] += dp[c][len];
            total[len] = min(k, total[len]);
        }
    }

    long long answer = 0;
    for (int len = n; len >= 1; len--) {
        long long take = min(k, total[len]);
        answer += take * (n - len);
        k -= take;
        if (k == 0)
            break;
    }

    // account for the single empty subsequence (length 0, cost n)
    if (k == 1) {
        answer += n;
        k = 0;
    }

    if (k > 0)
        cout << "-1" << "\n";
    else
        cout << answer << "\n";

    return 0;
}