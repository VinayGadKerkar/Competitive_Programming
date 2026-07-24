#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;
    int kthPoint = 0;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        if(val <= 0)
            break;
        k--;
        if(k == 0){
            kthPoint = val;
        }
        if(k < 0 && kthPoint != val)
            break;
        else
            count++;
    }
    cout << count << "\n";
}