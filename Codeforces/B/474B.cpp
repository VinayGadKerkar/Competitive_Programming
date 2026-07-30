#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n;
    vector<pair<int , int>> ranges;
    int lastRange = 1;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        ranges.push_back({lastRange , lastRange + x - 1});
        lastRange = ranges.back().second + 1;
    }
    cin >> m;
    while(m--){
        int target;
        cin >> target;
        int low = 0 , high = n - 1 , mid;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(target >= ranges[mid].first && target <= ranges[mid].second){
                ans = mid + 1;
                break;
            }else if(target > ranges[mid].second){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}