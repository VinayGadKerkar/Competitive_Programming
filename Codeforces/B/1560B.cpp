#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a , b , c;
        cin >> a >> b >> c;
        long long totalPairs = abs(a - b);
        long long maxNumber = totalPairs * 2;
        if(totalPairs < 2){
            cout << "-1" << endl;
            continue;
        }
        if(!(c >= 1 && c <= maxNumber) || !(a >= 1 && a <= maxNumber) || !(b >= 1 && b <= maxNumber)){
            cout << "-1" << "\n";
            continue;
        }
        if(c <= totalPairs)
            cout << c + totalPairs << "\n";
        else
            cout << c - totalPairs << "\n";
    }
}