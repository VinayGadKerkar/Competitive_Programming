#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++)
        cin >> coins[i];
    int totalSum = accumulate(coins.begin() , coins.end() , 0);
    sort(coins.begin() , coins.end() , greater<>());
    int curSum = 0;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        curSum += coins[i];
        totalSum -= coins[i];
        count++;
        if(curSum > totalSum)
            break;
        
    }
    cout << count << "\n";
}