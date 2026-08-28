#include<bits/stdc++.h>
using namespace std;
vector<int> parent , compSz;
int findParent(int v){
    if(v == parent[v])
        return v;
    return parent[v] = findParent(parent[v]);
}
void unite(int a , int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return;
    if(compSz[a] < compSz[b])
        swap(a , b);
    parent[b] = a;
    compSz[a] += compSz[b];
}
int main() {
    int n , k;
    cin >> n >> k;
    parent.resize(n + 1);
    compSz.assign(n + 1 , 1);
    for(int i = 1 ; i <= n ; i++)
       parent[i] = i;
    
    int ans = 0;
    for(int i = 0 ; i < k ; i++){
        int snack , person;
        cin >> snack >> person;
        if(findParent(snack) == findParent(person))
            ans++;
        else
            unite(snack , person);
    }
    cout << ans << "\n";
}