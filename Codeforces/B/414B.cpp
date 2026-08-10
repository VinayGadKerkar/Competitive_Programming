#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int dp[2001][2001];
long long solve(int k , int len, int last , int n) {
    if (len == k)
        return 1;

    if (dp[len][last] != -1)
        return dp[len][last];

    long long ans = 0;

    for (int next = last; next <= n; next += last) {
        ans += solve(k , len + 1, next , n);
        ans %= M;
    }

    return dp[len][last] = ans;
}
int main() {
    int n , k;
    cin >> n >> k;
    memset(dp , -1 , sizeof(dp));
    long long res = 0;
    for(int i = 1; i <= n ; i++){
        res = (res + solve(k , 1 , i , n));
        res %= M;
    }
    cout << res << "\n";
}