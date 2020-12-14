#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e5;

ll res[N];
int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	string a, b; cin>>a>>b;
	reverse(all(a)); reverse(all(b));
	ll alen=a.size(), blen=b.size(), sz;
	for(ll i=0; i<blen; i++){
		ll x=b[i]-'0', idx=i, carry=0;
		for(ll j=0; j<alen; j++){
			ll y=a[j]-'0';
			ll curr=res[idx]+(x*y)+carry;
			res[idx]=curr%10;
			carry=curr/10;
			idx++;
		}
		if(carry>0){res[idx++]=carry;}
		sz=idx;
	}
	while(res[sz]==0){
		sz--;
	}
	for(ll i=sz; i>=0; i--){
		cout<<res[i];
	}
	return 0;
}

