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
void solve(){
    ll n;
    cin>>n;
    vl v(n);
    loop(i,0,n-1)cin>>v[i];
    ll sum=0, mx=INT_MIN;
    loop(i,0,n-1)mx= max(mx,v[i]);
    if(mx<0)cout<<mx<<endl;
    else{
    loop(i,0,n-1){
        sum+=v[i];
        if(sum<0)sum=0;
        mx = max(mx,sum);
    }
    cout<<mx<<endl;
}
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
