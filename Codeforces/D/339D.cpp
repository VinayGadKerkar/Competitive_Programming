#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &st , int i , int l , int r , vector<int> &a , bool isOr){
    if(l == r){
        st[i] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(st , 2 * i + 1 , l , mid , a , !isOr);
    build(st , 2 * i + 2 , mid + 1 , r , a , !isOr);
    if(isOr)
        st[i] = st[2 * i + 1] | st[2 * i + 2];
    else
        st[i] = st[2 * i + 1] ^ st[2 * i + 2];
}

void update(vector<int> &st , int i , int l , int r , int idx , int val , bool isOr){
    if(l == r){
        st[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if(idx <= mid)
        update(st , 2 * i + 1 , l , mid , idx , val , !isOr);
    else
        update(st , 2 * i + 2 , mid + 1 , r , idx , val , !isOr);
    if(isOr)
        st[i] = st[2 * i + 1] | st[2 * i + 2];
    else
        st[i] = st[2 * i + 1] ^ st[2 * i + 2];
}

int main() {
    int n , m;
    cin >> n >> m;
    int N = pow(2 , n);
    vector<int> a(N);
    for(int i = 0 ; i < N ; i++)
        cin >> a[i];
    vector<int> st(4 * N , 0);
    bool rootOr = (n % 2 == 1);
    build(st , 0 , 0 , N - 1 , a , rootOr);
    while(m--){
        int idx , val;
        cin >> idx >> val;
        update(st , 0 , 0 , N - 1 , idx - 1 , val , rootOr);
        cout << st[0] << "\n";
    }
    return 0;
}