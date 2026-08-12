#include<bits/stdc++.h>
using namespace std;
struct Info {
    int dp , index;
};

void update(vector<Info> &st , int i , int l , int r , int idx , int val , int originalIdx){
    if(l == r){
        if(val > st[i].dp)
            st[i] = {val, originalIdx};
        return;
    }
    int mid = l + (r - l) / 2;
    if(idx <= mid)
        update(st , 2 * i + 1 , l , mid , idx , val , originalIdx);
    else
        update(st , 2 * i + 2 , mid + 1 , r , idx , val , originalIdx);

    if(st[2*i+1].dp >= st[2*i+2].dp)
        st[i] = st[2*i+1];
    else
        st[i] = st[2*i+2];
}

Info query(vector<Info> &st , int i , int l , int r , int start , int end){
    if(l > end || r < start) return {0 , -1};
    if(l >= start && r <= end) return st[i];

    int mid = l + (r - l) / 2;
    Info left = query(st , 2 * i + 1 , l , mid , start , end);
    Info right= query(st , 2 * i + 2 , mid + 1 , r , start , end);
    if(left.dp >= right.dp)
        return left;
    return right;
}

int main() {
    long long n , d;
    cin >> n >> d;
    vector<long long> heights(n);
    long long maxHeight = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        cin >> heights[i];
        maxHeight = max(maxHeight , heights[i]);
    }
    vector<long long> temp = heights;
    sort(temp.begin() , temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    vector<int> dp(n , 1);
    vector<Info> st(4 * temp.size(), {0, -1});
    vector<int> parent(n , -1);
    int m = temp.size();
    for(int i = 0 ; i < n ; i++){
        
        int leftEnd = upper_bound(temp.begin(), temp.end(), heights[i] - d) - temp.begin() - 1;
        int rightStart = lower_bound(temp.begin(), temp.end(), heights[i] + d) - temp.begin();
        Info maxLeft = {0 , -1};
        Info maxRight = {0 , -1};
        if(leftEnd >= 0)
            maxLeft = query(st , 0 , 0 , m - 1 , 0 , leftEnd);
        if(rightStart < m)
            maxRight = query(st , 0 , 0 , m - 1 , rightStart , m - 1);
        int best;
        if(maxLeft.dp >= maxRight.dp){
            best = maxLeft.dp;
            parent[i] = maxLeft.index; 
        }else{
            best = maxRight.dp;
            parent[i] = maxRight.index;
        }
        dp[i] = best + 1;
        int idx = lower_bound(temp.begin(), temp.end(), heights[i]) - temp.begin();
        update(st , 0 , 0 , m - 1 , idx , dp[i] , i);
    }

    int last = max_element(dp.begin() , dp.end()) - dp.begin();

    vector<int> ans;

    while(last != -1){
        ans.push_back(last);
        last = parent[last];
    }

    reverse(ans.begin() , ans.end());
    cout << ans.size() << "\n";
    for(int idx : ans)
        cout << idx + 1 << " ";
    cout << "\n";
}   