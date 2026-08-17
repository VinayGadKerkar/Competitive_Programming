#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i]; 
        if(k <= n) {
            long long maxSum = 0;
            for(int i = 0 ; i < k ; i++)
                maxSum += a[i];

            long long curMax = maxSum;
            for(int i = k; i < n ; i++){
                curMax -= a[i - k];
                curMax += a[i];
                maxSum = max(curMax , maxSum);
            }

            long long ans = maxSum + 1LL * k * (k - 1) / 2;
            cout << ans << "\n";
        }
        else {
            long long totalSum = accumulate(a.begin() , a.end() , 0LL);
            long long ans = totalSum + 1LL * n * k - 1LL * n * (n + 1) / 2;
            cout << ans << "\n";
        }

    }
}