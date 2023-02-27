#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll row, col;
        cin >> row >> col;
        ll grid[row + 5][col + 5];
        for (ll i = 1; i <= row; i++) {
            for (ll j = 1; j <= col; j++) {
                cin >> grid[i][j];
            }
        }
        ll Min = min(row, col);
        if (Min == 1) {
            ll sum = 0;
            if (Min == 1) {
                if (row == 1) {
                    for (ll i = 1; i <= col; i++) sum += grid[1][i];
                }
                else {
                    for (ll i = 1; i <= row; i++) sum += grid[i][1];
                }
            }
            cout << sum << "\n";
        }
        else {
            //right down
            ll right = 0, res = -1e18;
            for (ll i = 1; i <= col; i++) {
                right += grid[1][i];
            }
            ll sum = 0;
            for (ll i = 2; i <= row; i++) {
                sum += grid[i][col];
            }
            res = max(res, right + sum);

            //right diagonal down
            sum = 0;
            for (ll i = 2; i <= row; i++) {
                sum += grid[i][col - 1];
            }
            sum += grid[row][col];
            res = max(res, right + sum);

            //right diagonal right down
            sum = 0;
            sum = grid[2][col - 1];
            for (ll i = 2; i <= row; i++) {
                sum += grid[i][col];
            }
            res = max(res, right + sum);

            //down right
            ll down = 0;
            for (ll i = 1; i <= row; i++) {
                down += grid[i][1];
            }
            sum = 0;
            for (ll i = 2; i <= col; i++) {
                sum += grid[row][i];
            }
            res = max(res, down + sum);

            //down diagonal right
            sum = 0;
            for (ll i = 2; i <= col; i++) {
                sum += grid[row - 1][i];
            }
            sum += grid[row][col];
            res = max(res, down + sum);

            //down diagonal down right
            sum = grid[row - 1][2];
            for (ll i = 2; i <= col; i++) {
                sum += grid[row][i];
            }
            res = max(res, down + sum);

            //diagonal right down
            sum = grid[1][1];
            for (ll i = 2; i <= col; i++) {
                sum += grid[2][i];
            }
            for (ll i = 3; i <= row; i++) {
                sum += grid[i][col];
            }
            res = max(res, sum);

            //diagonal down right
            sum = grid[1][1];
            for (ll i = 2; i <= row; i++) {
                sum += grid[i][2];
            }
            for (ll i = 3; i <= col; i++) {
                sum += grid[row][i];
            }
            res = max(res, sum);

            cout << res << "\n";
        }
    }
    return 0;
}
