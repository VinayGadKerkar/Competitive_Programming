#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> time(n);
    for(int i = 0 ; i < n ; i++)
        cin >> time[i];
    sort(time.begin() , time.end());
    int count = 0 , wait = 0;
    for(int x : time){
        if(wait <= x){
            count++;
            wait += x;
        }else
            continue;
    }
    cout << count << "\n";
}