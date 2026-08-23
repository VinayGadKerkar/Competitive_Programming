#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> candies(n) , oranges(n);
        int minCandy = INT_MAX , minOrange = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            cin >> candies[i];
            minCandy = min(minCandy , candies[i]);
        }
            
        for(int i = 0 ; i < n ; i++){
            cin >> oranges[i];
            minOrange = min(minOrange , oranges[i]);
        }
        
        long long count = 0;
        for(int i = 0 ; i < n ; i++){
            int orange_cnt = oranges[i] - minOrange;
            int candies_cnt = candies[i] - minCandy;
            count += (max(orange_cnt , candies_cnt));
        }
        cout << count << "\n";
    }
}