#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , m , x , y;
    cin >> n >> m >> x >> y;
    vector<pair<int , int>> soldiers;
    vector<pair<int , int>> vests;
    for(int i = 0 ; i < n ; i++){
        int soldier;
        cin >> soldier;
        soldiers.push_back({soldier , i + 1});
    }
    for(int i = 0 ; i < m ; i++){
        int vest;
        cin >> vest;
        vests.push_back({vest , i + 1});
    }
    sort(soldiers.begin() , soldiers.end());
    sort(vests.begin() , vests.end());
    vector<pair<int , int>> fits;
    int sp = 0 , vp = 0;
    while(sp < n && vp < m){
        if(((soldiers[sp].first - x) <= vests[vp].first) && ((soldiers[sp].first + y) >= vests[vp].first)){
            fits.push_back({soldiers[sp].second , vests[vp].second});
            sp++;
            vp++;
        }else if((soldiers[sp].first - x) > vests[vp].first){
            vp++;
        }else{
            sp++;
        }
    }
    cout << fits.size() << "\n";
    for(auto fit : fits)
        cout << fit.first << " " << fit.second << "\n";
}