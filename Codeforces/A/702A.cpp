#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
       vector<int> dp(n  , 1);
    int current = 1;
    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1])
            current++;
        else
            current = 1;

        ans = max(ans, current);
    }

    cout << ans << "\n";
    return 0;
}