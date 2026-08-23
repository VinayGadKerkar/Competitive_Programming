#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    const int MAXT = 200000;

    vector<int> diff(MAXT + 2, 0);

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        diff[l]++;
        diff[r + 1]--;
    }
    for(int i = 1; i <= MAXT; i++) {
        diff[i] += diff[i - 1];
    }

    for(int i = 1; i <= MAXT; i++) {
        diff[i] = diff[i] >= k;
    }
    
    for(int i = 1; i <= MAXT; i++) {
        diff[i] += diff[i - 1];
    }

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << diff[b] - diff[a - 1] << '\n';
    }

    return 0;
}