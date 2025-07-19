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
vp v;
vl dp;
ll search(ll pos,ll n,ll endTime){
    ll low = pos+1, high = n-1, ans = n;
    while(low <= high){
        ll mid = (low+high)>>1;
        if(v[mid].f >= endTime){ // If the start time is greater than or equal to endTime
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
ll help(ll pos,ll n){
    if(pos >= n) return 0;
    if(dp[pos] != -1) return dp[pos];

    ll ans = help(pos+1,n); // Skip the current interval
    ll nextPos = search(pos,n,v[pos].s);
    ans = max(ans, 1 + help(nextPos,n)); // Include the current interval and find the next non-overlapping interval
    return dp[pos] = ans;
}
void solve(){
    ll n;
    cin >> n;
    loop(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    sort(all(v));
    dp.resize(n,-1);
    ll ans = help(0,n);
    cout << ans << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}