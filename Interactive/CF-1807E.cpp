//https://codeforces.com/contest/1807/problem/E

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n; 
        cin >> n;
        vector<ll> v(n), cum(n + 5);
        cum[0] = 0;
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
            cum[i + 1] = cum[i] + v[i];
        }
        ll L = 1, R = n, res;
        while (L <= R) {
            ll mid = L + (R - L) / 2;
            ll tot = mid - L + 1;
            cout << "? " << tot << " ";
            for (ll i = L; i <= mid; i++) {
                cout << i << " ";
            }
            cout << "\n";
            fflush(stdout);
            ll response, sum = cum[mid] - cum[L - 1];
            cin >> response;
            if (response > sum) {
                res = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        cout << "! " << res << "\n";
        fflush(stdout);
    }
    return 0;
}



