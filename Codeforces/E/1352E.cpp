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
        vector<int> a(n);
        int maxElem = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            maxElem = max(maxElem , a[i]);
        }
        vector<bool> special(maxElem + 5 , false);
        for(int i = 0 ; i < n ; i++){
            int sum = a[i];
            for(int j = i + 1 ; j < n ; j++){
                sum += a[j];
                if(sum > maxElem) break;
                special[sum] = true;
            }
        }
        int count = 0;
        for(int &x : a){
            if(special[x])
                count++;
        }
        cout << count << "\n";
    }
}