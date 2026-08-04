#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<vector<int>> operations;
    for(int i = 0 ; i < m ; i++){
        int left , right , value;
        cin >> left >> right >> value;
        operations.push_back({left - 1 , right - 1 , value});
    }
    vector<vector<int>> queries;
    for(int i = 0 ; i < k ; i++){
        int left , right;
        cin >> left >> right;
        queries.push_back({left - 1 , right - 1});
    }

    vector<int> diffArr1(m , 0);
    for(auto &query : queries){
        diffArr1[query[0]]++;
        if(query[1] + 1 < m)
            diffArr1[query[1] + 1]--;
    }
    for(int i = 1 ; i < m ; i++)
        diffArr1[i] += diffArr1[i - 1];
    
    vector<long long> diffArr2(n , 0);
    for(int i = 0 ; i < m ; i++){
        int left = operations[i][0] , right = operations[i][1] , value = operations[i][2];
        int freq = diffArr1[i];
        diffArr2[left] += (value * 1LL * freq);
        if(right + 1 < n)
            diffArr2[right + 1] -= (value * 1LL * freq);
    }

    for(int i = 1 ; i < n ; i++)
        diffArr2[i] += diffArr2[i - 1];

    for(int i = 0 ; i < n ; i++)
        cout << a[i] + diffArr2[i] << " ";
    
    return 0;
}