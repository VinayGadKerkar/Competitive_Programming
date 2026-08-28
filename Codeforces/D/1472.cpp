#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        priority_queue<int> odd, even;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if(num & 1)
                odd.push(num);
            else
                even.push(num);
        }

        long long pts_alice = 0;
        long long pts_bob = 0;

        bool aliceTurn = true;

        while(!odd.empty() || !even.empty()) {

            if(aliceTurn) {
                if(odd.empty()) {
                    pts_alice += even.top();
                    even.pop();
                }else if(even.empty()) {
                    odd.pop();
                }else {
                    int evenNum = even.top();
                    int oddNum = odd.top();

                    if(evenNum >= oddNum) {
                        pts_alice += evenNum;
                        even.pop();
                    }
                    else {
                        odd.pop();
                    }
                }
            }else {
                if(even.empty()) {
                    pts_bob += odd.top();
                    odd.pop();
                }else if(odd.empty()) {
                    even.pop();
                }else {
                    int evenNum = even.top();
                    int oddNum = odd.top();

                    if(oddNum >= evenNum) {
                        pts_bob += oddNum;
                        odd.pop();
                    }else {
                        even.pop();
                    }
                }
            }

            aliceTurn = !aliceTurn;
        }

        if(pts_alice > pts_bob)
            cout << "Alice\n";
        else if(pts_bob > pts_alice)
            cout << "Bob\n";
        else
            cout << "Tie\n";
    }

    return 0;
}