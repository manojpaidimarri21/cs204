#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define pll pair < long long, long long >
#define pli pair <long long, int>
#define pil pair <int, long long>
#define pii pair < int, int>
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
ll mod=1e9+7;
ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%mod;
    ll ans=power(num,r/2)%mod;
    if(r%2==0) {
        return (ans*ans)%mod;
    } return (((ans*ans)%mod)*num)%mod;
}
ll modinv(ll num){
    return power(num,mod-2);
}
//------------------------------------------------------------
 
int main(){
	fastio;
	int n;
	cin>>n;
	string s;
	map<string,int> m;
	forl(i,0,n){
		cin>>s;
		string a=s;
		reverse(a.beg,a.en);
		if(s!=a){
			m[s]=1;
		}
	}
	int ans=0;
	for(auto i:m){
		string a=i.fi;
		reverse(a.beg,a.en);
		if(m.find(a)!=m.en) ans=1;
	}
	if(ans) cout<<"YES";
	else cout<<"NO";
	return 0;
}
