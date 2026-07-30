#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5;
int main() {
    vector<bool> seiveArr(N , false);
    seiveArr[0] = true;
    seiveArr[1] = true;
    for(int i = 2 ; i < N ; i++){
        if(!seiveArr[i])
            for(long long j = 1LL * i * i ; j < N ; j += i){
                seiveArr[j] = true;
            }
    }
    int n;
    cin >> n;
    while(n--){
        long long i;
        cin >> i;
        long long r = sqrt(i);
        if(r * r == i && !seiveArr[r])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
}