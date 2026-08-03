#include<bits/stdc++.h>
using namespace std;
int main() {
    int n , k;
    cin >> n >> k;
    vector<int> planks(n);
    for(int i = 0 ; i < n ; i++)
        cin >> planks[i];
    vector<int> prefix(n , 0);
    prefix[0] = planks[0];
    for(int i = 1 ; i < n ; i++)
        prefix[i] = prefix[i - 1] + planks[i];
    int bestIdx = -1 , bestSum = INT_MAX;
    for(int i = 0 ; i <= n - k ; i++){
        int curSum = prefix[i + k - 1] - (i > 0 ? prefix[i - 1] : 0);
        if(curSum < bestSum){
            bestIdx = i + 1;
            bestSum = curSum;
        }
    }
    cout << bestIdx << "\n";
}