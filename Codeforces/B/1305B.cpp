#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, j = n - 1;
    vector<int> opens, closes;
    while (i < j) {
        while (i < j && s[i] != '(') i++;
        while (i < j && s[j] != ')') j--;
        if (i < j) {
            opens.push_back(i + 1);   // 1-indexed
            closes.push_back(j + 1);
            i++;
            j--;
        }
    }
    if (opens.empty()) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
        cout << (opens.size() + closes.size()) << "\n";
        for (int idx : opens) cout << idx << " ";
        for (int idx = closes.size() - 1; idx >= 0; idx--) cout << closes[idx] << " ";
        cout << "\n";
    }
}