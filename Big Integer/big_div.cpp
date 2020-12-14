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

	string a; ll b;
	cin>>a>>b;
	ll alen=a.size(),temp=0,idx=0;
	if(a[0]=='0'){
		cout<<"Divisible\n"; return 0;
	}
	while(temp<b and idx<alen){
		temp=temp*10+a[idx++]-'0';
	}
	string ans;
	while(temp>=b){
		ans+=(temp/b)+'0';
		temp%=b;
		if(idx>=alen){break;}
		temp=temp*10+a[idx++]-'0';
	}
	if(temp!=0 or sz==0){cout<<"Not Divisible\n";}
	else{cout<<ans<<"\nDivisible\n";}
	return 0;
}

