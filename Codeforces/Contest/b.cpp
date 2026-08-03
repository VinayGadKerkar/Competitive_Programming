#include <bits/stdc++.h>
using namespace std;

bool possible(int runs, int zeroes, int ones, char start) {
    int zeroRuns = (start == '0') ? (runs + 1) / 2 : runs / 2;
    int oneRuns = (start == '1') ? (runs + 1) / 2 : runs / 2;
    if (zeroRuns == 0 && zeroes > 0) return false;
    if (oneRuns == 0 && ones > 0) return false;
    return (zeroes >= zeroRuns && ones >= oneRuns);
}

string build(char start, int zeroes, int ones, int runs) {
    int zeroRuns = (start == '0') ? (runs + 1) / 2 : runs / 2;
    int oneRuns = (start == '1') ? (runs + 1) / 2 : runs / 2;

    string res;
    char cur = start;

    while (zeroRuns > 0 || oneRuns > 0) {
        if (cur == '0') {
            int len;
            if (zeroRuns == 1)
                len = zeroes;          
            else
                len = 1;

            res += string(len, '0');
            zeroes -= len;
            zeroRuns--;
            cur = '1';
        }
        else {
            int len;
            if (oneRuns == 1)
                len = ones;            
            else
                len = 1;

            res += string(len, '1');
            ones -= len;
            oneRuns--;
            cur = '0';
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int runs = n - k;

        
        vector<pair<int,int>> cnts = {
            {n/2, n - n/2},
            {n - n/2, n/2}
        };

        bool found = false;

        for (auto [zeroes, ones] : cnts) {
            if (possible(runs, zeroes, ones, '0')) {
                cout << build('0', zeroes, ones, runs) << "\n";
                found = true;
                break;
            }

            if (possible(runs, zeroes, ones, '1')) {
                cout << build('1', zeroes, ones, runs) << "\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << "\n";
    }

    return 0;
}