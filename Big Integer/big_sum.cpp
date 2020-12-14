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
		ll curr=(a[i]-'0')+(b[i]-'0');
		res[idx++]=(curr+carry)%10;
		carry=(curr+carry)/10;
	}
	if(alen<blen){
		a=b; alen=blen;
	}
	for(ll i=sz; i<alen; i++){
		res[idx++]=((a[i]-'0')+carry)%10;
		carry=((a[i]-'0')+carry)/10;
	}
	if(carry>0){res[idx++]=carry;}
	for(ll i=idx-1; i>=0; i--){
		cout<<res[i];
	}
	return 0;
}

