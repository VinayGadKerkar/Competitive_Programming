#include<bits/stdc++.h>
using namespace std;
vector<int> parent , grpSize;
int findParent(int v){
    if(v == parent[v])
        return v;
    return parent[v] = findParent(parent[v]);
}

void unite(int u , int v){
    u = findParent(u);
    v = findParent(v);
    if(u == v) return;
    if(grpSize[u] < grpSize[v])
        swap(u , v);
    parent[v] = u;
    grpSize[u] += grpSize[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m;
    cin >> n >> m;
    parent.resize(n + 1);
    grpSize.assign(n + 1 , 1);

    for(int i = 1 ; i <= n ; i++)
        parent[i] = i;
    
    for(int i = 0 ; i < m ; i++){
        int k;
        cin >> k;
        int previousFr;

        if(k > 0){
            cin >> previousFr;
        }
        for(int j = 1 ; j < k ; j++){
            int newFriend;
            cin >> newFriend;
            unite(previousFr , newFriend);
            previousFr = newFriend;
        }
    }

    for(int i = 1 ; i <= n ; i++)
        cout << grpSize[findParent(i)] << " ";
    

}