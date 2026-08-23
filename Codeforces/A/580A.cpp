#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxSeg = 1;
    int curSeg = 1;
    int curMax = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        if(x >= curMax){
            curSeg++;
            maxSeg = max(maxSeg , curSeg);
        }else{
            curSeg = 1;
        }
        curMax = x;
    }

    cout << maxSeg << "\n";
    return 0;
}