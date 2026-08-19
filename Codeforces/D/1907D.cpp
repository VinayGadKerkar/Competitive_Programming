#include<bits/stdc++.h>
using namespace std;

bool canJump(long long k , int n , vector<pair<long long , long long>> &segments){
    pair<long long , long long> possible = {0 , 0};
    for(auto segment : segments){
        possible.first -= k;
        possible.second += k;
        possible.first = max(possible.first , segment.first);
        possible.second = min(possible.second , segment.second);
        if(possible.first > possible.second) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<long long , long long>> segments;
        for(int i = 0 ; i < n ; i++){
            long long start , end;
            cin >> start >> end;
            segments.push_back({start , end});
        }
        long long low = 0 , high = 1e9 , mid;
        long long ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(canJump(mid , n , segments)){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        cout << ans << "\n";
    }
}