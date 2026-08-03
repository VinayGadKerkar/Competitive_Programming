#include<bits/stdc++.h>
using namespace std;


bool check(long long cntRecipe , vector<long long> required , vector<long long> &available , vector<long long> &prices , long long k){
    
    long long requiredK = 0;
    for(int i = 0 ; i < required.size() ; i++){
        long long totalNeeded = cntRecipe * required[i];
        if (totalNeeded > available[i]) {
            requiredK += (totalNeeded - available[i]) * prices[i];
        }   
        if(requiredK > k) return false;
    }
    return requiredK <= k;
}

int main(){
    string recipe;
    cin >> recipe;
    vector<long long> available(3 , 0);
    cin >> available[0] >> available[1] >> available[2];
    vector<long long> prices(3 , 0);
    cin >> prices[0] >> prices[1] >> prices[2];
    long long k;
    cin >> k;

    vector<long long> required(3 , 0);
    for(char &ch : recipe){
        if(ch == 'B')
            required[0]++;
        if(ch == 'S')
            required[1]++;
        if(ch == 'C')
            required[2]++;
    }

    long long low = 0 , high = 1e13;
    long long ans = 0;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(check(mid , required , available , prices , k)){
            ans = mid;
            low = mid + 1;
        }else
            high = mid - 1;
    }
    cout << ans << "\n";
}