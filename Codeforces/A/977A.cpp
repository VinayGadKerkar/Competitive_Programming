#include<bits/stdc++.h>
using namespace std;
int main() {
    long long num , k;
    cin >> num >> k;
    while(k-- && num > 0){
        if(num % 10 == 0)
            num /= 10;
        else
            num--;
        
    }
    cout << num << "\n";
}