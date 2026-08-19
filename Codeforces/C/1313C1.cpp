#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    vector<int> temp = a;
    vector<long long> candidate(n);
    int maxIdx = -1;
    long long maxCandidate = LLONG_MIN;
    for(int i = 0 ; i < n ; i++){
        candidate[i] = a[i];
        for(int j = i - 1 ; j >= 0 ; j--)
            temp[j] = min(temp[j] , temp[j + 1]);
        
        for(int j = i + 1 ; j < n ; j++)
            temp[j] = min(temp[j] , temp[j - 1]);
        candidate[i] = accumulate(temp.begin() , temp.end() , 0LL);
        if(candidate[i] > maxCandidate) {
            maxCandidate = candidate[i];
            maxIdx = i;
        }
        temp = a;
    }
    for(int j = maxIdx - 1 ; j >= 0 ; j--)
        a[j] = min(temp[j] , a[j + 1]);
        
    for(int j = maxIdx + 1 ; j < n ; j++)
        a[j] = min(temp[j] , a[j - 1]);
    for(int x : a)
        cout << x << " ";
}