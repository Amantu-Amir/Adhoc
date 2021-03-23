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
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll siz,n,x;
		cin>>siz>>n;
		deque<ll>Q;
		cout<<"Case "<<T<<":\n";
		for(ll i=0; i<n; i++){
			string s; cin>>s;
			if(s=="pushLeft"){
				cin>>x;
				if(Q.size()==siz){
					cout<<"The queue is full\n";
				}
				else{
					cout<<"Pushed in left: "<<x<<"\n";
					Q.push_front(x);
				}
			}
			else if(s=="pushRight"){
				cin>>x;
				if(Q.size()==siz){
					cout<<"The queue is full\n";
				}
				else{
					cout<<"Pushed in right: "<<x<<"\n";
					Q.push_back(x);
				}
			}
			else if(s=="popLeft"){
				if(Q.size()==0){
					cout<<"The queue is empty\n";
				}
				else{
					cout<<"Popped from left: "<<Q.front()<<"\n";
					Q.pop_front();
				}
			}
			else{
				if(Q.size()==0){
					cout<<"The queue is empty\n";
				}
				else{
					cout<<"Popped from right: "<<Q.back()<<"\n";
					Q.pop_back();
				}
			}
		}
	}
	return 0;
}

