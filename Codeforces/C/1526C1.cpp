#include<bits/stdc++.h>
using namespace std;
const long long NINF = -1e15;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1 , vector<long long>(n + 1 , NINF));
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= i ; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j >= 1 && dp[i - 1][j - 1] + a[i] >= 0 && dp[i - 1][j - 1] != NINF)
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + a[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            if(dp[i][j] >= 0)
                ans = max(ans , j);
    cout << ans << "\n";
}