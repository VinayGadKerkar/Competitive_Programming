#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        string b;
        cin >> b;
        if(b.size() <= 2){
            cout << b << "\n";
            continue;
        }
        string a = "";
        for(int i = 0 ; i < b.size() ; i += 2){
            a += b[i];
        }
        a += b[b.size() - 1];
        cout << a << "\n";        
    }
}