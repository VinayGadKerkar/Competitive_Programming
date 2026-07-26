#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int val = 0;
    while(t--){
        string s;
        cin >> s;
        if(s.find("++") != string::npos)
            val++;
        else
            val--;
    }
    cout << val << "\n";
    return 0;
}