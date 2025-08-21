#include <bits/stdc++.h>
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
#define vl                    vector<ll>
#define P                     pair<ll,ll>
#define vp                    vector<pair<ll,ll>> 
#define lb                    lower_bound
#define ub                    upper_bound
#define N                     100000
using namespace std;

// If you actually need pbds elsewhere, keep these:
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

vl v;
ll dp[N+1][101]; // assumes m <= 100 (as in CSES)
ll M;         // store m globally for bounds

// func(pos, n, prev): number of ways to fill positions [pos..n]
// given that the previous value (at pos-1) is 'prev'
ll func(ll pos, ll n, ll prev){
    if (pos > n) return 1; // all positions assigned

    if (dp[pos][prev] != -1) return dp[pos][prev];

    ll ans = 0;

    if (v[pos] == 0) {
        // choose current value x in [prev-1, prev+1] ∩ [1, M]
        ll L = max(1LL, prev - 1);
        ll R = min(M,  prev + 1);
        for (ll x = L; x <= R; ++x) {
            ans += func(pos + 1, n, x);
            if (ans >= MOD) ans -= MOD;
        }
    } else {
        if (llabs(v[pos] - prev) <= 1) {
            ans = func(pos + 1, n, v[pos]) % MOD;
        } else {
            ans = 0;
        }
    }

    return dp[pos][prev] = ans;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    M=m;
    v.resize(n);
    loop(i, 0, n-1) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    if (n == 1) {
        // single element sequence
        if (v[0] == 0) ans = m % MOD;
        else ans = 1;
        cout << ans << endl;
        return;
    }

    if (v[0] != 0) {
        // first value fixed; start from position 1 with prev = v[0]
        ans = func(1, n-1, v[0]) % MOD;
    } else {
        // first value can be anything 1..m
        for (ll x = 1; x <= m; ++x) {
            ans += func(1, n-1, x);
            if (ans >= MOD) ans -= MOD;
        }
    }

    cout << ans % MOD << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
