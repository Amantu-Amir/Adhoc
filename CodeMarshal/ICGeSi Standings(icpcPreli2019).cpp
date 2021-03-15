#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prln(a) cout<<a<<"\n"
#define nl cout<<"\n"
#define P(a) cout<<a
#define PP(a,b) cout<<a<<" "<<b
#define PPP(a,b,c) cout<<a<<" "<<b<<" "<<c
#define inf 2147483647

//---------------------------------------------------------------------------//

void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//
const ll N=2e5+50;
const ll mod=1e9+7;


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		ll id, sol[n+5], tp[n+5], fz_sub[n+5];
		map<ll,ll>fz_penalty;
		vector<ll>penalty[100];
		for(ll i=0; i<n; i++){
			cin>>id;
			cin>>sol[id]>>tp[id]>>fz_sub[id];
			ll pen,add=0;
			for(ll j=0; j<fz_sub[id]; j++){
				cin>>pen; add+=pen;
				penalty[id].pb(pen);
			}
			fz_penalty[id]=add;
		}
		vector<ll>rank(n);
		for(ll i=0; i<n; i++){
			cin>>rank[i];
		}
		ll ok=1;
		ll curr_solved, curr_penalty;
		for(ll i=0; i<(n-1) and ok==1; i++){
			ll tot_solved = sol[rank[i]]+fz_sub[rank[i]];
			ll tot_penalty = tp[rank[i]]+fz_penalty[rank[i]];
			if(i==0){
				if(tot_solved<sol[rank[i+1]]){
					ok=0; break;
				}
				else{
					if(tot_solved==sol[rank[i+1]] and tot_penalty>tp[rank[i+1]]){
						ok=0; break;
					}
					else{
						curr_solved=tot_solved;
						curr_penalty=tot_penalty;
					}
				}
			}
			else{
				ll curr=fz_sub[rank[i]];
				while(tot_solved>curr_solved and curr>0){
					tot_solved--; curr--;
					tot_penalty-=penalty[rank[i]][curr];
				}
				if(tot_solved==curr_solved){
					if(curr_penalty>tot_penalty){
						if(curr==0){
							ok=0; break;
						}
						tot_solved--;
						tot_penalty-=penalty[rank[i]][curr-1];
					}
				}
				if(tot_solved>=sol[rank[i+1]]){
					if(tot_solved==sol[rank[i+1]] and tot_penalty>tp[rank[i+1]]){
						ok=0; break;
					}
					curr_solved=tot_solved;
					curr_penalty=tot_penalty;
				}
				else{
					ok=0; break;
				}
			}
		}
		cout<<"Case "<<T<<": ";
		if(ok==1){
			cout<<"We respect our judges :)\n";
		}
		else{
			cout<<"Say no to rumour >:\n";
		}
	}
	return 0;
}



