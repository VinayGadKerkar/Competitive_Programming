#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int maxEvenPos = INT_MIN;
        int minOddPos = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            if (i & 1) {          
                minOddPos = min(minOddPos, x);
            } else {               
                maxEvenPos = max(maxEvenPos, x);
            }
        }   
        if(n & 1){
            cout << "NO" << "\n";
            continue;
        }
        if(maxEvenPos < minOddPos - 1)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}