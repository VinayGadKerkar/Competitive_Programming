#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , t;
    cin >> n >> t;
    vector<int> time(n);
    for(int i = 0 ; i < n ; i++)
        cin >> time[i];
    int left = 0;
    int maxBooks = 0 , curBooks = 0 , curTime = 0;
    for(int right = 0 ; right < n ; right++){
        curTime += time[right];
        curBooks++;
        while(left <= right && curTime > t){
            curBooks--;
            curTime -= time[left];
            left++;
        }
        maxBooks = max(curBooks , maxBooks);
    }
    cout << maxBooks << endl;
}