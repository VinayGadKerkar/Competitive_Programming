#include<bits/stdc++.h>
using namespace std;
long long dp[5001][5001];
const long long NEG = -(1LL << 60);

long long solve(int index , int cnt , vector<long long> &windows , int m , int n){
    if(cnt == 0)
        return 0;
    if( index >= windows.size())
        return NEG;
    if(dp[index][cnt] != -1) return dp[index][cnt];
    long long skip = solve(index + 1 , cnt , windows , m , n);
    long long take = windows[index] + solve(index + m , cnt - 1 , windows , m , n);
    return dp[index][cnt] = max(take , skip);
}
int main(){
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    memset(dp , -1 , sizeof(dp));
    vector<long long> windows(n - m + 1);
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];
    for(int i = 0 ; i < n - m + 1 ; i++){
        windows[i] = prefix[i + m] - prefix[i];
    }
    cout << solve(0 , k , windows , m , n);
}