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
#define N                     200000
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
void solve(){
    ll n,x;
    cin >> n >> x;
    vp v;
    loop(i,0,n-1){
        ll a;
        cin>>a;
        v.pb({a,i});
    }
    sort(all(v));
    ll low =0, high = n-1;
    while(low<high){
        if(v[low].f + v[high].f < x)low++;
        else if(v[low].f + v[high].f > x)high--;
        else{
            ll mn = min(v[low].s, v[high].s);
            ll mx = max(v[low].s, v[high].s);
            cout << mn +1 << " " << mx + 1 << endl;
            return; // Found the pair, exit
        }
    }
    cout << "IMPOSSIBLE" << endl; // No valid pair found
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}