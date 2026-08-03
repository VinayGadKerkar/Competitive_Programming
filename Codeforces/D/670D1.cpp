#include<bits/stdc++.h>
using namespace std;

bool check(int requiredQ , vector<long long> &need , vector<long long> &available , int k){
    int n = need.size();

    for(int i = 0 ; i < n ; i++){
        long long availableQ = available[i] / need[i];
        if(availableQ >= requiredQ) continue;
        long long remainder = available[i] % need[i];
        long long needQ = requiredQ - availableQ;
        k -= ((needQ * need[i]) - remainder);
        if(k < 0)
            return false;
    }

    return k >= 0;
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<long long> need(n) , available(n);
    for(int i = 0 ; i < n ; i++)
        cin >> need[i];
    for(int i = 0 ; i < n ; i++)
        cin >> available[i];

    
    long long high = LLONG_MAX , low = 0 , mid;

    for (int i = 0; i < n; i++) {
        high = min(high, (available[i] + k) / need[i]);
    }
    int ans = 0;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(check(mid , need , available , k)){
            ans = mid;
            low = mid + 1;
        }else
            high = mid - 1;
    }
    cout << ans << "\n";
}