#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , d;
    cin >> n >> d;
    vector<pair<int , int>> friends;
    for(int i = 0 ; i < n ; i++){
        int amt , factor;
        cin >> amt >> factor;
        friends.push_back({amt , factor});
    }
    sort(friends.begin() , friends.end() , [](auto a , auto b) {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
    if(n <= 1){
        cout << friends[0].second << endl;
        return 0;
    }
    int left = 0;
    long long curFactor = 0 , bestFactor = -1;
    for(int right = 0 ; right < n ; right++){
        curFactor += friends[right].second;
        while(friends[right].first - friends[left].first >= d){
            curFactor -= friends[left].second;
            left++;
        }
        bestFactor = max(curFactor , bestFactor);
    }

    cout << bestFactor << "\n";
    return 0;

}