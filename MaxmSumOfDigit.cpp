///**Bismillahir Rahmanir Rahim.**
#include <bits/stdc++.h>
#define mem(a, v)         memset(a, v, sizeof a)
#define vec(m)             vector<ll>m
#define ast(v)              sort(v.begin(),v.end())
#define dst(v)              sort(v.begin(),v.end(), greater <int> ())
#define ass(tmp, v)        tmp.assign(v.begin(), v.end())
#define rep(i, l, r)        for (int i = l; i < r; i++)
#define rep2(i, l, r)       for (int i = l-1; i >= r; i--)
#define pb                  push_back
#define pp                  pair<ll,ll>
#define mp                  make_pair
#define T                   true
#define F                   false
#define S                   second
#define f                   first
#define PI                  3.1415926

//-----------------------------------***********************----------------------------------------------//

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 200050;
const int mod = 1e9+7;

ll calc(ll n)
{
    ll sum = 0;
    while(n)
    {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tcase = 1, cas = 0;
    while(tcase--)
    {
        ll n;
        cin >> n;
        n++;            //See 55 line for this reason

        ll p = 1, ans = INT_MIN;
        while(n)
        {
            ans = max(ans, calc(n-1));
            n -= (n%p);
            p *= 10;
        }
        cout << ans << endl;

        //printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
