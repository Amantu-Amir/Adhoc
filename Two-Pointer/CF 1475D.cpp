#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e9;

bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
	if(a.F==b.F){return a.S>b.S;}
	return a.F<b.F;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	while(t--){
		ll n,free; 
		cin>>n>>free;
		vector<ll>A(n);
		vector<pair<ll,ll>>v;
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		ll a;
		vector<ll>one,two;
		for(ll i=0; i<n; i++){
			cin>>a;
			if(a==1){
				one.pb(A[i]);
			}
			else{
				two.pb(A[i]);
			}
		}
		sort(all(one));
		sort(all(two)); reverse(all(two));
		ll sz=one.size();
		for(ll i=0; i<sz; i++){
			v.pb({1,one[i]});
		}
		sz=two.size();
		for(ll i=0; i<sz; i++){
			v.pb({2,two[i]});
		}
		ll L=0,R=0,cnt=0,sum=0,res=N;
		while(L<=R and R<n){
			if(sum<free){
				sum+=v[R].S;
				cnt+=v[R].F;
				R++;
			}
			while(sum>=free){
				res=min(res,cnt);
				sum-=v[L].S;
				cnt-=v[L].F;
				L++;
			}
		}
		if(res==N){res=-1;}
		cout<<res<<"\n";
	}

	return 0;
}

