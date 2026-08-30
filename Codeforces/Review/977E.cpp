#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
bool dfs(int node , vector<vector<int>> &adj){
    vis[node] = true;
   
    bool hasCycle = adj[node].size() == 2;
    for(int child : adj[node]){
        if(vis[child]) continue;
        hasCycle &= dfs(child , adj);
    }
    return hasCycle;
}
int main() {
    int n , m;
    cin >> n >> m;
    vis.resize(n + 1 , false);
    vector<vector<int>> adj(n + 1);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            if(dfs(i , adj))
                count++;
        }
    }
    cout << count << "\n";
}