#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    if(n >= m){
        cout << n - m << "\n";
        return 0;
    }
    queue<pair<long long , int>> q;
    vector<bool> visited(2 * m + 2, false);
    q.push({n , 0});
    visited[n] = true;
    while(!q.empty()){
        auto [cur , dist] = q.front();
        q.pop();
        if(cur == m){
            cout << dist << "\n";
            break;
        }
        if(cur - 1 >= 0 && !visited[cur - 1]){
            visited[cur - 1] = true;
            q.push({cur - 1 , dist + 1});
        }
            
        if(cur * 2 <= 2 * m && !visited[cur * 2]){
            visited[cur * 2] = true;
            q.push({cur * 2 , dist + 1});
        } 
            
    }

}