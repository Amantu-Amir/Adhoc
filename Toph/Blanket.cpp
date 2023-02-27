#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll x, y, z, l, w, h;
        cin >> x >> y >> z >> l >> w >> h;
        vector<vector<ll>> v;
        v.push_back({x, y, z});
        v.push_back({x, z, y});
        v.push_back({y, z, x});
        v.push_back({y, x, z});
        v.push_back({z, y, x});
        v.push_back({z, x, y});
        ll res = INT_MAX;
        for (ll i = 0; i < 6; i++) {
            if (v[i][2] < h) continue;
            ll cnt = 0;
            if (l > v[i][0]) {
                ll temp = l;
                while (temp > v[i][0]) {
                    //cout << temp << " temp1\n";
                    temp = temp / 2 + (temp % 2 != 0);
                    cnt++;
                }
            }
            if (w > v[i][1]) {
                ll temp = w;
                while (temp > v[i][1]) {
                    //cout << temp << " temp2\n";
                    temp = temp / 2 + (temp % 2 != 0);
                    cnt++;
                }
            }
            //cout << cnt << " cnt\n";
            ll thickness = h, ck = cnt;
            while (ck) {
                thickness *= 2;
                ck--;
            }
            if (thickness <= v[i][2]) {
                res = min(res, cnt);
            }
        }
        if (res == INT_MAX) res = -1;
        cout << res << "\n";
    }
    return 0;
}
