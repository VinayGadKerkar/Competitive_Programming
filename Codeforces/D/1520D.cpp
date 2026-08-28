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
        vector<long long> a(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        unordered_map<long long , long long> map;
        long long count = 0;
        for(int i = 0 ; i < n ; i++){
            if(map.count(a[i] - i)){
                count += map[a[i] - i];
            }
            map[a[i] - i]++;
        }
        cout << count << "\n";
    }
    return 0;
}