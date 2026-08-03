#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    vector<int> prefix(n , 0);
    while(q--){
        int left , right;
        cin >> left >> right;
        prefix[left - 1]++;
        if(right < n)
            prefix[right]--;
    }
    for(int i = 1 ; i < n ; i++)
        prefix[i] += prefix[i - 1];
    
    sort(prefix.begin() , prefix.end());
    sort(a.begin() , a.end());
    long long ans = 0;
    for(int i = 0 ; i < n ; i++)
        ans += (prefix[i] * 1LL * a[i]);
    cout << ans << endl;
}