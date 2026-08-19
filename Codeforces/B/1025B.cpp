#include <bits/stdc++.h>
using namespace std;

bool check(long long x,
           const vector<long long>& a,
           const vector<long long>& b) {

    for(int i = 0; i < a.size(); i++) {
        if(a[i] % x != 0 && b[i] % x != 0)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    if(n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    vector<long long> candidates = {
        gcd(a[0], a[1]),
        gcd(a[0], b[1]),
        gcd(b[0], a[1]),
        gcd(b[0], b[1])
    };

    for(long long g : candidates) {

        if(g <= 1)
            continue;

        for(long long p = 2; p * p <= g; p++) {

            if(g % p == 0) {

                if(check(p, a, b)) {
                    cout << p << '\n';
                    return 0;
                }

                while(g % p == 0)
                    g /= p;
            }
        }

        if(g > 1 && check(g, a, b)) {
            cout << g << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}