#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e5;

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll res[N];
	string a, b; cin>>a>>b;
	reverse(all(a)); reverse(all(b));
	ll alen=a.size(), blen=b.size();
	ll sz=min(alen,blen), carry=0, idx=0;
	for(ll i=0; i<sz; i++){
		ll x=a[i]-'0', y=b[i]-'0'+carry;
		carry=0;
		if(x<y){x+=10;carry=1;}
		res[idx++]=x-y;
	}
	if(alen<blen){
		a=b; alen=blen;
	}
	for(ll i=sz; i<alen; i++){
		ll x=a[i]-'0', y=carry;
		carry=0;
		if(x<y){x+=10; carry=1;}
		res[idx++]=x-y;
	}
	if(res[idx-1]==0){idx--;}
	for(ll i=idx-1; i>=0; i--){
		cout<<res[i];
	}
	return 0;
}

