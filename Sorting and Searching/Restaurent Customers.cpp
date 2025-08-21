#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define pb                    push_back
#define f                     first
#define s                     second
#define mp                    make_pair
#define MOD                   1000000007
#define SZ(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t; cin>>t;while(t--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vl                    vector<ll>
#define P                     pair<ll,ll>
#define vp                    vector<pair<ll,ll>> 
#define lb                    lower_bound
#define ub                    upper_bound
#define N                     200000
using namespace std;
int32_t main(){
    ll n;
    cin >> n;
    vp a;
    loop(i,0,n-1){
        ll x,y;
        cin >> x>>y;
        a.pb(mp(x,1));
        a.pb(mp(y,0));
    }
    sort(all(a));
    ll ans=0,count=0;
    loop(i,0,2*n-1){
        if(a[i].s==1)count++;
        else count--;
        ans=max(ans,count);
    }
    cout<<ans<<endl;
    return 0;
}
