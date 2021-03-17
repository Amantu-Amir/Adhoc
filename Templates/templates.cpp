

//segment tree
void propagate(ll node, ll b, ll e){
	if(b!=e){
		ll mid=(b+e)/2;
		ll left=mid-b+1;
		ll right=e-(mid+1)+1;
		ll bame_lagbe=left-(tree[node*2].drop+tree[node*2].lazy);
		if(bame_lagbe>=tree[node].lazy){
			tree[node*2].lazy+=tree[node].lazy;
		}
		else{
			tree[node*2].lazy+=bame_lagbe;
			ll dane_lagbe=right-(tree[node*2+1].drop+tree[node*2+1].lazy);
			tree[node*2+1].lazy+=min(dane_lagbe,tree[node].lazy-bame_lagbe);
		}
		ll tot=(e-b+1)-tree[node].drop;
		tree[node].drop+=min(tot,tree[node].lazy);
	}
	else{
		tree[node].drop=1;
	}
	tree[node].lazy=0;
}


void update(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		ll lagbe=(e-b+1)-tree[node].drop;
		if(lagbe>=water){
			tree[node].lazy=water;
			water=0;
		}
		else{
			tree[node].lazy=lagbe;
			water-=lagbe;
		}
		if(tree[node].lazy>0){
			propagate(node,b,e);
		}
		return;
	}
	ll mid=(b+e)/2;
	update(node*2,b,mid,L,R);
	update(node*2+1,mid+1,e,L,R);
	tree[node].drop=(tree[node*2].drop+tree[node*2+1].drop);
	//cout<<node<<" "<<tree[node].drop<<"\n";
}


ll query(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return tree[node].drop;
	}
	ll mid=(b+e)/2;
	ll q1=query(node*2,b,mid,L,R);
	ll q2=query(node*2+1,mid+1,e,L,R);
	return q1+q2;
}





//Euler tour
void dfs(ll root){
	vis[root]=1;
	start[root]=curr;
	for(auto child:G[root]){
		if(vis[child]==0){
			dfs(child);
		}
	}
	finish[root]=curr++;
}





//Disjoin set
void init(){
	for(ll i=1; i<=N; i++){
		rep[i]=i;
	}
}

ll find_rep(ll n){
	if(n==rep[n]){return n;}
	return rep[n]=find_rep(rep[n]);
}

void join_node(ll u,ll v){
	u=find_rep(u);
	v=find_rep(v);
	if(u!=v){
		rep[u]=v;
	}
}




//Modular Inverse
//If mod is not prime;
void extended_euclide(ll a,ll b,ll &x, ll &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	ll x1,y1;
	extended_euclide(b,a%b,x1,y1);
	x=y1;
	y=x1-y1*(a/b);
	return;
}

ll modular_inverse(ll a){
	ll x,y;
	extended_euclide(a,mod,x,y);
	return x;
}

//Modular Inverse
//If mod is prime;
ll bin_pow(ll b,ll p){
	if(p==-1){			
		p=mod-2;
	}
	ll ret=1;
	while(p>0){
		if(p&1){
			ret=(ret*b)%mod;
		}
		p/=2;
		b=(b*b)%mod;
	}
	return ret;
}
/*
	(a/b)%mod = a%mod * m%mod
	Here, m = 1/b;
	res = (a%mod*m%mod)%mod
*/
bin_pow(b,-1);





//BFS
void bfs(int source){
    visited[source]=1;
    level[source]=0;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty() and !paici){
        int parent = Q.front(); Q.pop();
        int siz = G[parent].size();
        for(int i=0; i<siz; i++){
            int child = G[parent][i];
            if(visited[child]==0){
                visited[child]=1;
                level[child]=level[parent]+1;
                Q.push(child);
                if(child==dest){paici=1;break;}
            }
        }
    }
}





//Articulation point
void dfs(ll node,ll par){
	vis[node]=1;
	ll subtree=0;
	low[node]=in[node]=timer++;
	for(auto child:adj[node]){
		if(child==par){continue;}
		if(vis[child]==1){
			low[node]=min(low[node],in[child]);
		}
		else if(vis[child]==0){
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node] and par!=-1){
				cut_points.insert(node);
			}
			subtree++;
		}
	}
	vis[node]=2;
	if(par==-1 and subtree>1){
		cut_points.insert(node);
	}
}





//Bridges
void dfs(ll node,ll par){
	vis[node]=1;
	in[node]=low[node]=timer++;
	for(auto child:adj[node]){
		if(child==par){continue;}
		if(vis[child]==1){								//back edge
			low[node]=min(low[node],in[child]);
		}
		else if(vis[child]==0){
			dfs(child,node);
			if(low[child]>in[node]){
				bridges.pb({node,child});
			}
			low[node]=min(low[node],low[child]);
		}
	}
	vis[node]=2;
}




//DFS
void dfs(int root){
   vis[root]=true;
   for(int child:G[root]){
        if(vis[child]==0){
        	dfs(child);
        }
   }
}




///Strongly connected components
void pre_process(ll root){
	vis[root]=1;
	start[root]=somoy++;
	for(auto child:adj[root]){
		if(vis[child]==0){
			pre_process(child);
		}
	}
	finish[root]=somoy++;
}

void dfs(ll root){
	vis[root]=1;
	scc.pb(root);
	for(auto child:trans_adj[root]){
		if(vis[child]==0){
			dfs(child);
		}
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	rep(T,1,t+1){
		ll node,edge;
		cin>>node>>edge;
		ll u,v;
		rep(i,0,edge){
			cin>>u>>v;
			adj[u].pb(v);
			trans_adj[v].pb(u);
		}
		rep(i,1,node+1){
			if(vis[i]==0){
				pre_process(i);
			}
		}
		vector<pair<ll,ll>>P;
		rep(i,1,node+1){
			P.pb({finish[i],i});
		}
		sort(all(P));
		reverse(all(P));
		memset(vis,0,sizeof(vis));
		rep(i,0,node){
			if(vis[P[i].S]==0){
				scc.clear();
				dfs(P[i].S);
				ll sz=scc.size();
				rep(j,0,sz){
					cout<<scc[j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}





//Topological sort
void dfs(int root){
	vis[root] = true;
	start[root] = somoy++;
	for(auto i : G[root]){
		if(vis[i] == false){
			dfs(i);
		}
	}
	finish[root] = somoy++;
}

int32_t main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	int tc=1;
	for(int T=1; T<=tc; T++){
		int node, edge;
		cin>>node>>edge;
		int u, v;
		for(int i=0; i<edge; i++){
			cin>>u>>v;
			G[u].push_back(v);
		}
		for(int i=1; i<=node; i++){
			if(vis[i] == false){
				dfs(i);
			}
		}
		vector<pair<int,int>>p;
		for(int i=1; i<=node; i++){
			p.push_back(make_pair(finish[i],i));
		}
		sort(p.begin(),p.end());
		reverse(p.begin(),p.end());
		for(int i=0; i<node; i++){
			cout<<p[i].second<<" "<<p[i].first<<"\n";
		}
	}
	return 0;
}






//Policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>pds;

//tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>T;

void solve(){
    pds T;
    ll n,q; cin>>n>>q;
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++){
    	cin>>v[i];
    	T.insert(v[i]);
    }
    while(q--){
        char x; ll y,z; 
        cin>>x>>y>>z;
        if (x=='?'){
            cout<<(T.order_of_key(z+1) - T.order_of_key(y))<<"\n";
        }
        else{
            T.erase(T.find_by_order(T.order_of_key(v[y])));
            v[y] = z;
            T.insert(z);
        }
    }
}    
 /*
        order_of_key(n) : Find the position of n;
        find_by_order(idx) : Find the value of this position
 */





//Sparse table
void build_sparse_table(){
	logn[1]=0;
	for(ll i=2; i<=n; i++){
		logn[i]=logn[i/2]+1;
	}
	for(ll i=0; i<=logn[n]; i++){
		ll curr_len=(1<<i); //2^i
		for(ll j=0; (j+curr_len)<=n; j++){
			if(curr_len==1){
				table[i][j]=v[j];	//table[i][j],i=2^i elements,j=start pont
			}
			else{
				table[i][j]=min(table[i-1][j], table[i-1][j+(curr_len/2)]);
			}
		}
	}
}

ll get_min(ll L,ll R){
	ll p=logn[R-L+1];
	ll len=1<<p;	//2^p
	return min(table[p][L], table[p][R-len+1]);
}
//sum query
long long sum = 0;
for (int j = K; j >= 0; j--) {
    if ((1 << j) <= R - L + 1) {
        sum += st[L][j];
        L += 1 << j;
    }
}





//Trie
struct node{
    bool endmark;
    node* next[26 + 1];
    node(){
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
}*root;


void insert(char* str, int len){
    node* curr = root;
    for (int i = 0; i < len; i++){
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}


bool search(char* str, int len){
    node* curr = root;
    for (int i = 0; i < len; i++){
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}


void del(node* cur){
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete(cur);
}





//KMP
vector <int> calc(string pat){
    int l = pat.length();
    vector <int> lps(l,0);
    int idx = 0, j = 1;
    while(j < l){
        if(pat[idx] == pat[j]){
            lps[j] = idx+1;
            ++idx; ++j;
        }
        else{
            if(idx != 0){
                idx = lps[idx-1];
            }
            else{
                ++j;
            }
        }
    }
    return lps;
}

int solve(string text, string pat){
    vector <int> lps = calc(pat);
    int idx = 0, j = 0, l = text.length();
    int ans = 0;
    while(j < l){
        if(text[j] == pat[idx]){
            ++j; idx++;
        }
        else{
            if(idx != 0){
                idx = lps[idx-1];
            }
            else{
                ++j;
            }
        }
        if(idx == pat.length()){
            ans++; idx = lps[idx-1];
        }
    }
    return ans;
}







//Lowest common ancestor
void dfs(ll root){
	vis[root]=true;
	ll sz=G[root].size();
	for(ll i=0; i<sz; i++){
		ll child = G[root][i].F;
		ll cost = G[root][i].S;
		if(vis[child]==false){
			label[child] = label[root]+1;
			dis[child] = dis[root]+cost;
			parent[child] = root;
			sparse[child][0] = root;
			dfs(child);
		}
	}
}

void pre_process(ll n){
	for(ll j=1; (1<<j)<n; j++){
		for(ll i=1; i<=n; i++){
			sparse[i][j] = sparse[sparse[i][j-1]][j-1];
		}
	}
}

ll query(ll u, ll v){
	if(label[u]<label[v]){
		swap(u,v);
	}
	ll lg=0;
	while((1<<lg)<=label[u]){
		lg++;
	}
	lg--;
	if(label[u]!=label[v]){
		for(ll i=lg; i>=0; i--){
			if((label[u]-(1<<i))>=label[v]){
				u=sparse[u][i];
			}
		}
	}
	if(u==v){return u;}
	for(ll i=lg; i>=0; i--){
		if(sparse[u][i]!=-1 and sparse[u][i]!=sparse[v][i]){
			u=sparse[u][i]; v=sparse[v][i];
		}
	}
	return parent[u];
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	while(t--){
		ll n; cin>>n;
		ll u,v;
		for(ll i=0; i<(n-1); i++){
			cin>>u>>v;
			G[u].pb({v,0});
			G[v].pb({u,1});			//Reverse cost 1
		}
		label[1]=0; dis[1]=0;
		parent[1]=1;
		dfs(1);
		pre_process(n);
		ll q; cin>>q;
		while(q--){
			cin>>u>>v;
			ll lca=query(u,v);
			cout<<"Lowest Common Ancestor = "<<lca<<"\n";
			ll aa=(label[u]-dis[u])-(label[lca]-dis[lca]);
			ll bb=dis[v]-dis[lca];
			ll res=aa+bb;
			cout<<"Distance = "<<res<<"\n";
		}
	}

	return 0;
}





//Digit of factorial
double a=0;
vector<double>v(N+50);
for(ll i=1; i<=N; i++){
	a=a+log10(i);
	v[i]=a;
}
ll t; scanf("%lld",&t);
for(ll T=1; T<=t; T++){
	ll n,b; scanf("%lld%lld",&n,&b);
	ll res=(v[n]/log10(b))+1;
	printf("Case %lld: %lld\n",T,res);
}






//Big sum
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




//Big sub
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





//Big mult
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





//Big div
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




//Sum of divisors
void sum_of_divisors(ll n){
    ll srt=sqrt(n+1),res=1;
    for(ll i=0; prime[i]<srt; i++){
        if(n%prime[i]==0){
            ll cnt=0;
            while(n%prime[i]==0){
                cnt++; n/=prime[i];
            }
            res*=(pow(prime[i],cnt+1)-1)/(prime[i]-1);
        }
    }
    if(n>1){
        res*=(pow(n,2)-1)/(n-1);
    }
    cout<<res;
}





//Number of divisors
int NOD(int n){
    int till = sqrt(n+1);
    int p, divisor = 1;
    for(int i = 0; prime[i] <= till; i++){
        if(n%prime[i] == 0){
            p = 1;
            while(n%prime[i] == 0){
                n /= prime[i];
                p++;
            }
            till = sqrt(n);
            divisor *= p;
        }
    }
    if(n > 1)
        divisor *= 2;
    return divisor;
}

int NOD(int n){
    int ans = 0;
    for(int i = 1; i*i <= n; i++){
        if(i*i == n) ans += 1;
        else if(n%i == 0) ans += 2;
    }
    return ans;
}




//Prime factorization
void primeFactorization(int n){
    int tmp = sqrt(n), pos = 0;
    for(int i = 0; prime[i] <= tmp; i++){
        if(n%prime[i] == 0){
            while(n%prime[i] == 0){
                n /= prime[i];
                primeFactor[pos++] = prime[i];
            }
        }
    }
    if(n > 1)
        primeFactor[pos++] = n;
}







//Grid visit
bool valid(ll r, ll c){
	return r<8 and r>=0 and c<8 and c>=0;
}

void bfs(ll x, ll y, ll a, ll b){
	vis[x][y] = 1;
	level[x][y] = 0;
	queue<pair<ll,ll>> Q;
	Q.push({x,y});
	while(!Q.empty()){
		pair<ll,ll> u = Q.front();
		Q.pop();
		ll r = u.first, c = u.second;
		if(r == a and c == b) break;
		for(ll i=0; i<8; i++){
			x = r+fx[i], y = c+fy[i];
			if(valid(x,y)){
				if(vis[x][y] == 0){
					vis[x][y] = 1;
					level[x][y] = level[r][c] +1;
					Q.push({x,y});
				}
			}
		}
	}
}





//Sieve
void sieve(){
	isPrime.reset();
	for(ll i=2; (i*i)<=N; i++){
		if(isPrime[i]==0){
			for(ll j=(i*i); j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(ll i=2; i<=N; i++){
		if(isPrime[i]==0){
			prime.pb(i);
		}
	}
}





//Longest palindromic subtring
//Manacher
void manacher(string s){
    string T;
    T += "$"; int sl = s.length();
    for(int i=0; i<sl; i++){
        T += "#"; T += s[i];
    }
    T += "#@";

    vector<int>P(T.length(),0);
    int center = 0, right = 0;
    int tl = T.length();

    for(int i=1; i<tl-1; i++){
        int mir = 2*center - i;
        if(i<right){
            P[i] = min(right-i, P[mir]);
        }
        while(T[i+(1+P[i])] == T[i-(1+P[i])]){
            P[i]++;
        }
        if((i+P[i])>right){
            center = i; right = i+P[i];
        }
    }

    int mxLen = 0; center = 0;
    for(int i=1; i<tl-1; i++){
        if(mxLen<P[i]){
            mxLen = P[i]; center = i;
        }
    }

    int left = (center-1-mxLen)/2;
    right = (center-1+mxLen)/2-1;
    //cout<<left<<" "<<right<<"\n";
    for(int i=left; i<=right; i++){
        cout<<s[i];
    }
}




