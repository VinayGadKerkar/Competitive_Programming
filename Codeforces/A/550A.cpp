#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n < 4){
        cout << "NO" << "\n";
        return 0;
    }
    vector<int> ab;
    vector<int> ba;
    for(int i = 0 ; i < n - 1 ; i++){
        if(s[i] == 'A' && s[i + 1] == 'B')
            ab.push_back(i);
        if(s[i] == 'B' && s[i + 1] == 'A')
            ba.push_back(i);
    }
    if(ab.empty() || ba.empty()){
        cout << "NO" << "\n";
        return 0;
    }
    if(abs(ab.front() - ba.back()) >= 2 || abs(ba.front() - ab.back()) >= 2)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}