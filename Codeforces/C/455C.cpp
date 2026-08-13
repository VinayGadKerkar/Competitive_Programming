#include<bits/stdc++.h>
using namespace std;
vector<int> diameter , parent , compSize , visited;

int find(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int a , int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(compSize[a] < compSize[b])
        swap(a , b);
    parent[b] = a;
    compSize[a] += compSize[b];
}

pair<int , int> dfs(int par , int node , int dist , vector<vector<int>> &adj){

    pair<int , int> best = {node , dist};
    visited[node] = true;
    for(int child : adj[node]){
        if(par == child) continue;

        auto cur = dfs(node , child , dist + 1 , adj);
        if(cur.second > best.second)
            best = cur;
    }
    return best;
}

// pair<int,int> bfs(int start,
//                   vector<vector<int>> &adj,
//                   vector<bool> &visited) {

//     vector<int> dist(adj.size(), -1);
//     queue<int> q;

//     q.push(start);
//     dist[start] = 0;
//     visited[start] = true;

//     int farthestNode = start;

//     while(!q.empty()) {
//         int node = q.front();
//         q.pop();

//         if(dist[node] > dist[farthestNode])
//             farthestNode = node;

//         for(int next : adj[node]) {
//             if(dist[next] != -1)
//                 continue;

//             dist[next] = dist[node] + 1;
//             visited[next] = true;
//             q.push(next);
//         }
//     }

//     return {farthestNode, dist[farthestNode]};
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m , q;
    cin >> n >> m >> q;
    diameter.resize(n + 1);
    parent.resize(n + 1);
    compSize.assign(n + 1 , 1);
    for(int i = 1 ; i <= n ; i++)
        parent[i] = i;
    
    vector<vector<int>> adj(n + 1);
    
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        unite(u , v);
    }
    visited.assign(n + 1 , false);
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            auto first = dfs(-1 , i , 0 , adj);
            auto second = dfs(-1 , first.first , 0 , adj);
            
            int d = second.second;
            int root = find(i);
            diameter[root] = d;
        }
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            cout << diameter[find(x)] << "\n";
        }else if(type == 2){
            int x , y;
            cin >> x >> y;
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY)
                continue;
            int d1 = diameter[rootX];
            int d2 = diameter[rootY];
            unite(x , y);
            int newDiameter = max({d1 , d2 , (d1 + 1) / 2 + 1 + (d2 + 1) / 2});
            int newRoot = find(x);
            diameter[newRoot] = newDiameter;   
        }
    }


        
}