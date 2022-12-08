#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    ll t = 1;
    cin >> t;
    cout << "CALL FORWARDING OUTPUT\n";
    for (ll T = 1; T <= t; T++) {
        vector<vector<ll>> v;
        ll source, start, duration, target;
        while (cin >> source) {
            if (source == 0) break;
            cin >> start >> duration >> target;
            v.pb({source, start, start + duration, target});
        }
        ll time, extension;
        cout << "SYSTEM " << T << "\n";
        while (cin >> time) {
            if (time == 9000) break;
            cin >> extension;
            unordered_map<ll, bool> mark;
            mark[extension] = 1;
            ll siz = v.size(), ext = extension, ok = 0;
            for (ll i = 0; i < siz; i++) {
                if (time >= v[i][1] and time <= v[i][2] and ext == v[i][0]) {
                    ext = v[i][3];
                    if (mark[ext]) {
                        ok = 1;
                        printf("AT %04lld CALL TO %04lld RINGS 9999\n", time, extension);
                        break;
                    }
                    mark[ext] = 1;
                    i = -1;
                }
            }
            if (ok == 0) {
                printf("AT %04lld CALL TO %04lld RINGS %04lld\n", time, extension, ext);
            }
        }
    }
    cout << "END OF OUTPUT\n";
    return 0;
}





