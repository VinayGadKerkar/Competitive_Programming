#include<bits/stdc++.h>
using namespace std;
int main() {
    const int maxV = 100000;
    int n;
    cin >> n;
    vector<long long> freq(maxV + 1 , 0);
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<long long> best(maxV + 1 , 0);
    best[1] = freq[1];
    for(int i = 2 ; i <= maxV ; i++)
        best[i] = max(best[i - 1] , best[i - 2] + 1LL * i * freq[i]);
    cout << best[maxV] << "\n";
}