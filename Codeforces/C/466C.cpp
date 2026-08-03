#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    long long totalSum = accumulate(a.begin() , a.end() , 0LL);
    if(totalSum % 3 != 0){
        cout << "0" << endl;
        return 0;
    }

    long long target = totalSum / 3;
    long long cntTarget = 0;
    for(int i = 1 ; i < n ; i++)
        a[i] += a[i - 1];
    
    long long ans = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        if(a[i] == 2 * target)
            ans += cntTarget;
        
        if(a[i] == target)
            cntTarget++;
    }

    cout << ans << endl;
    return 0;
}