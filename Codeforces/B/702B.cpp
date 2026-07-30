#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        a[i] = x;
    }
    long long count = 0;
    unordered_map<long long , int> freq;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 32 ; j++){
            long long need = (1LL << j) - a[i];
            count += freq[need];
        }
        freq[a[i]]++;
    }
    
    cout << count << "\n";
}