#include<bits/stdc++.h>
using namespace std;

string getlargest(int m , int s){
    string res;
    for(int i = 0 ; i < m ; i++){
        int remainingPositions = m - i - 1;
        for(int d = 9 ; d >= 0 ; d--){
            int remainingSum = s - d;
            if(0 <= remainingSum && remainingSum <= 9 * remainingPositions){
                res += ('0' + d);
                s = remainingSum;
                break;
            }
        }
    }
    
    return res;
}

string getSmallest(int m , int s){
    string res;   
    for(int i = 0 ; i < m ; i++){
        int remainingPositions = m - i - 1;
        int start = (i == 0) ? 1 : 0;
        for(int d = start ; d <= 9 ; d++){
            int remainingSum = s - d;
            if(0 <= remainingSum && remainingSum <= 9 * remainingPositions){
                res += ('0' + d);
                s = remainingSum;
                break;
            }
        }
    }
    
    return res;
}

int main() {
    int m , s;
    cin >> m >> s;
    if (s == 0) {
        if (m == 1)
            cout << "0 0\n";
        else
            cout << "-1 -1\n";
    }else if (s > 9 * m) 
        cout << "-1 -1\n";
    else
        cout << getSmallest(m, s) << " " << getlargest(m, s) << "\n";
       
}