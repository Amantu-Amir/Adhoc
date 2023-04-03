#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//https://codeforces.com/gym/101021/problem/1

int main() {
    ll L = 1, R = 1000000, res;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        cout << mid << "\n";
        fflush(stdout);
        string response;
        cin >> response;
        if (response == "<") {
            R = mid - 1;
        }
        else {
            res = mid;
            L = mid + 1;
        }
    }
    cout << "! " << res << "\n";
    fflush(stdout);
    return 0;
}



