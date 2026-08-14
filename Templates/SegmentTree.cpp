#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long sum , prefix , suffix , best;
};
Node mergeNodes(Node left , Node right){
    //Use case specific
    Node res;
    res.sum = left.sum + right.sum;
    res.prefix = max(left.prefix , left.sum + right.prefix);
    res.suffix = max(right.suffix , right.sum + left.suffix);
    res.best = max({
                   left.best , right.best , left.suffix + right.prefix
                   });
    return res;
}
void build(Node* st , int i , int l , int r , vector<long long> &arr){
    if(l == r){
        st[i] = {arr[l] , max(0LL , arr[l]) , max(0LL , arr[l]) , max(0LL , arr[l])};
        return;
    }
    int mid = l + (r - l)/2;
    build(st , 2 * i + 1 , l , mid , arr);
    build(st , 2 * i + 2 , mid + 1 , r , arr);
    st[i] = mergeNodes(st[2 * i + 1] , st[2 * i + 2]);
}

Node query(Node* st , int i , int l , int r , int start , int end){
    if(l > end || r < start) return {0 , LLONG_MIN , LLONG_MIN , LLONG_MIN};
    if(l >= start && r <= end) return st[i];
    int mid = l + (r - l)/2;
    Node left = query(st , 2 * i + 1 , l , mid , start , end);
    Node right = query(st , 2 * i + 2 , mid + 1 , r , start , end);
    if(left.best == INT_MIN) return right;
    if(right.best == INT_MIN) return left;
    return mergeNodes(left , right);
}
void update(Node* st , int i , int l , int r , long long val , int idx){
    if(l == r){
        st[i] = {val, max(0LL, val), max(0LL, val), max(0LL, val)};
        return;
    }
    int mid = l + (r - l)/2;
    if(idx <= mid)
        update(st , 2 * i + 1 , l , mid , val , idx);
    else
        update(st , 2 * i + 2 , mid + 1 , r , val , idx);
    st[i] = mergeNodes(st[2 * i + 1] , st[2 * i + 2]);
}

int main(){
    int n , q;
    cin >> n >> q;
    Node* st = new Node[4 * n];
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    build(st , 0 , 0 , n - 1 , arr);
//    while(q--){
//        long long val;
//        int idx;
//        cin >> idx >> val;
//        update(st , 0 , 0 , n - 1 , val , idx - 1);
//        cout << st[0].best;
//        cout << endl;
//    }
    while(q--){
        int a , b;
        cin >> a >> b;
        cout << query(st , 0 , 0 , n - 1 , a - 1 , b - 1).best;
        cout << endl;
    }
}
