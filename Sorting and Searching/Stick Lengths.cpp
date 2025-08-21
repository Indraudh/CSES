#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define pb                    push_back
#define f                     first
#define s                     second
#define mp                    make_pair
#define MOD                   1000000007
#define sz(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t; cin>>t;while(t--)
#define vl                    vector<ll>
#define P                     pair<ll,ll>
#define vp                    vector<pair<ll,ll>> 
#define lb                    lower_bound
#define ub                    upper_bound
#define N                     1000000
using namespace std;
ll func(ll ele,vl v){
    ll temp=0;
    for(auto it:v){
        temp += abs (it-ele);
    }
    return temp;
}
void solve(){
    ll n;
    cin>>n;
    vl v(n);
    loop(i,0,n-1)cin>>v[i];
    ll low = 1e18, high = -1e18;
    loop(i,0,n-1){
        cin>>v[i];
        low = min(v[i],low);
        high = max(high,v[i]);
    }
    while(high-low>=3){ // applying ternary search
        ll mid1 = low + (high - low)/3;
        ll mid2 = high - (high-low)/3;
        ll x = func (mid1,v);
        ll y = func (mid2,v);
        if(x>y)low = mid1;
        else if(x<y)high = mid2;
        else {
            low = mid1;
            high = mid2;
        }
    }
    ll ans = 1e18;
    loop(i,low,high){
        ans = min(ans,func(i,v));
    }
    cout<<ans<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
