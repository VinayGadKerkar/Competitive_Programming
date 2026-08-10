#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    int t , k;
    cin >> t >> k;
    vector<pair<int,int>> queries;
    int maxRange = INT_MIN , minRange = INT_MAX;
    while(t--){
        int start , end;
        cin >> start >> end;
        maxRange = max(maxRange , end);
        minRange = min(minRange , start);
        queries.push_back({start , end});
    }
    const long long MOD = 1e9 + 7;
    vector<long long> dp(maxRange + 1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i <= maxRange ; i++){
        dp[i] = (dp[i - 1] + (i - k >= 0 ? dp[i - k] : 0)) % MOD;
    }
    vector<long long> prefix(maxRange + 1 , 0);
    prefix[0] = dp[0];
    for(int i = 1 ; i <= maxRange ; i++)
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;

    for(auto [l , r] : queries){
        long long res = (prefix[r] - prefix[l - 1] + MOD) % MOD;
        cout << res << "\n";
    }
    
    return 0;
}