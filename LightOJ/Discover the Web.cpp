#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define inf 2147483647

//---------------------------------------------------------------------------//

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
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
		vector<string>A;
		ll siz=1,idx=0;
		A.pb("http://www.lightoj.com/");
		cout<<"Case "<<T<<":\n";
		while(1){
			string type;
			cin>>type;
			if(type=="QUIT"){
				break;
			}
			if(type=="VISIT"){
				string s; cin>>s;
				cout<<s<<"\n";
				A.insert(A.begin()+idx+1,s);
				idx++; siz=idx+1;
			}
			else if(type=="BACK"){
				idx--;
				if(idx<0){
					idx=0;
					cout<<"Ignored\n";
				}
				else{
					cout<<A[idx]<<"\n";
				}
			}
			else{
				idx++;
				if(idx==siz){
                    idx--;
					cout<<"Ignored\n";
				}
				else{
					cout<<A[idx]<<"\n";
				}
			}
		}
	}
	return 0;
}

