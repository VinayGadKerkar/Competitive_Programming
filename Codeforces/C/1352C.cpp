#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n , k;
        cin >> n >> k;
        cout << k + (k - 1) / (n - 1) << "\n";
    }
    return 0;

}