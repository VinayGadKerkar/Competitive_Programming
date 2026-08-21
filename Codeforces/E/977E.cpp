#include<bits/stdc++.h>
using namespace std;
bool dfs(int node , vector<bool> &vis , vector<vector<int>> &adj){
    vis[node] = true;
    
    bool hasCycle = (adj[node].size() == 2);
    for(int child : adj[node]){
        if(vis[child]) continue;
        hasCycle &= dfs(child , vis , adj);
    }

    return hasCycle;
}
int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1 , false);
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]) continue;
        if(dfs(i , vis , adj))
            ans++;
    }
    cout << ans << "\n";
}