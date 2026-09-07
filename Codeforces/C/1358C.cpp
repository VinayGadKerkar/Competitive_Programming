#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long x , y , m , n;
        cin >> x >> y >> m >> n;
        long long ans = (x - m)  * (y - n) + 1;
        cout << ans << "\n";
    }
}