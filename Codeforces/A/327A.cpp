#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ones = 0;
    int zeroes = 0;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] == 0)
            zeroes++;
        else
            ones++;
    }
    int cur = 0;
    int best = INT_MIN;

    for (int x : a) {
        int gain = (x == 0 ? 1 : -1);

        cur = max(gain, cur + gain);
        best = max(best, cur);
    }

    cout << ones + best << '\n';
}