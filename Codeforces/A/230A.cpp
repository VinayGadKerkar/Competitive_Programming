#include<bits/stdc++.h>
using namespace std;

int main() {
    int s , n;
    cin >> s >> n;
    vector<pair<int , int>> dragons;
    for(int i = 0 ; i < n ; i++){
        int xVal , yVal;
        cin >> xVal >> yVal;
        dragons.push_back({xVal , yVal});
    }
    sort(dragons.begin() , dragons.end() , [](auto a , auto b){
        if(a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
    
    
    for(int i = 0 ; i < n ; i++){
        if(dragons[i].first >= s){
            cout << "NO" << "\n";
            return 0;
        }
        s += dragons[i].second;
    }
    cout << "YES" << "\n";

    return 0;
}