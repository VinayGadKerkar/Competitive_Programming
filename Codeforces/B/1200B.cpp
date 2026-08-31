#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n , m , k;
        cin >> n >> m >> k;
        vector<int> heights(n + 1);
        for(int i = 1 ; i <= n ; i++)
            cin >> heights[i];
        bool reached = true;
        for(int i = 1; i <= n ; i++){
            if(i == n) break;
            int cur = heights[i] , next = heights[i + 1];
            int target = max(next - k , 0);
            int delta = target - cur;
            if(delta > 0){
                m -= delta;
                if(m < 0){
                    reached = false;
                    break;
                }
            }else
                m += (-delta);
        }
        if(reached)
            cout << "YES\n";
        else
            cout << "NO\n";
    }  
}
 

