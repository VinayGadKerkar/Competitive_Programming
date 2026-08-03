#include<bits/stdc++.h>
using namespace std;

int dfs(int par , int index , vector<vector<int>> &adj , int m , int curM  , vector<bool> &cats){
    if (curM > m)
        return 0;
    bool isLeaf = true;
    int ans = 0;
    for(int child : adj[index]){
        if(par == child) continue;
        isLeaf = false;
        int next;
        if(cats[child])
            next = curM + 1;
        else
            next = 0;
        if(next > m) continue;
        ans += dfs(index , child , adj , m , next , cats);
    }
    if(isLeaf)
        return 1;
    
    return ans;
}

int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> cats(n + 1);
    for(int i = 1 ; i <= n ; i++){
        bool in;
        cin >> in;
        cats[i] = in;
    }
    for(int i = 0 ; i < n - 1 ; i++){
        int par , child;
        cin >> par >> child;
        adj[par].push_back(child);
        adj[child].push_back(par);
    }
    cout << dfs(0 , 1 , adj , m , cats[1] ? 1 : 0 , cats);
}