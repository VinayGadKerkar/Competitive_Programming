#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string b;
        cin >> b;
        string a = "1";
        string d = b[0] == '1' ? "2" : "1";
        for(int i = 1 ; i < n ; i++){
            if(b[i] == '0'){
                if(d[i - 1] == '1')
                    a.push_back('0');
                else
                    a.push_back('1');
            }else{
                if(d[i - 1] == '2')
                    a.push_back('0');
                else
                    a.push_back('1');
            }
            int ch1 = a[i] - '0';
            int ch2 = b[i] - '0';
            int ch3 = ch1 + ch2;
            d += to_string(ch3);
        }
        cout << a << "\n";
    }
}