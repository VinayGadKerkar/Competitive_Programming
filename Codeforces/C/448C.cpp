#include<bits/stdc++.h>
using namespace std;

int solve(int left , int right , int painted ,  vector<int> &a){
    if(left > right){
        return 0;
    }
    int mid = min_element(a.begin() + left  , a.begin() + right + 1) - a.begin();
    int minHeight = a[mid];
    int horizontal = minHeight - painted;
    int i = left;
    while(i <= right){
        if(a[i] == minHeight){
            i++;
            continue;
        }

        int start = i;
        while(i <= right && a[i] > minHeight)
            i++;
        horizontal += solve(start , i - 1 , minHeight , a);
    }
    int vertical = right - left + 1;
    return min(vertical , horizontal);
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    cout << solve(0 , n - 1 , 0 , a);
}