#include<bits/stdc++.h>
using namespace std;

int query(vector<int> &st , int i , int l , int r , int start , int end){
    if(r < start || l > end)
        return 0;
    if(l >= start && r <= end)
        return st[i];
    int mid = l + (r - l) / 2;
    int left = query(st , 2 * i + 1 , l , mid , start , end);
    int right = query(st , 2 * i + 2 , mid + 1 , r , start , end);
    return right + left;
}

void update(vector<int> &st , int i , int l , int r , int idx){
    if(l == r){
        st[i]++;
        return;
    }
    int mid = l + (r - l) / 2;
    if(idx <= mid)
        update(st , 2 * i + 1 , l , mid , idx);
    else
        update(st , 2 * i + 2 , mid + 1 , r , idx);
    st[i] = st[2*i+1] + st[2*i+2];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    vector<int> leftFreq(n);
    vector<int> rightFreq(n);
    unordered_map<int , int> freq;

    vector<int> st(4 * n , 0);
    for(int i = 0 ; i < n ; i++){
        freq[a[i]]++;
        leftFreq[i] = freq[a[i]];
    }
    freq.clear();
    for(int i = n - 1 ; i >= 0 ; i--){
        freq[a[i]]++;
        rightFreq[i] = freq[a[i]];
    }

    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += query(st, 0, 1, n, rightFreq[i] + 1, n);
        update(st, 0, 1, n, leftFreq[i]);
    }
    cout << ans << "\n";
}