#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n , x , y;
        cin >> n >> x >> y;
        int initialParity = x % 2;
        for(int i = 0 ; i < n ; i++){
            long long a;
            cin >> a;
            initialParity ^= (a % 2);
        }
        if(initialParity == (y % 2))
            cout << "Alice" << "\n";
        else
            cout << "Bob" << "\n";
    }
    return 0;
}