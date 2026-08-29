#include<bits/stdc++.h>
using namespace std;
bool check(long long time , vector<long long> &a , vector<long long> &b , int n){
    long long curSum = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] <= time && b[i] <= time){
            continue;
        }
        if(a[i] > time && b[i] > time)
            return false;
        if(a[i] > time && b[i] <= time){
            curSum += b[i];
            continue;
        }
    }
    return curSum <= time;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n) , b(n);
        long long maxTime = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
            
        for(int i = 0 ; i < n ; i++){
            cin >> b[i];
            maxTime += a[i];
        }
        long long ans = -1;
        long long low = 0 , high = maxTime;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(mid , a , b , n)){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        } 
        cout << ans << "\n";
    }
}