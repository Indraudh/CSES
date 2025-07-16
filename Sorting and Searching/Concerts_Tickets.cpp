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
    ll n,m;
    cin >> n >> m;
    multiset<ll> a;
    loop(i,0,n-1) {
        ll x;
        cin >> x;
        a.insert(x); // Insert elements into the multiset
    }
    loop(i,0,m-1){
        ll x;
        cin >> x;
        auto it = a.lower_bound(x); // Find the first element not less than x
        if(*it == x){
            cout<<x<<endl;
            a.erase(it); // Remove the element if it matches x
        }
        else if(it == a.begin()){
            cout<<"-1"<<endl; // If no element is greater than or equal to x
        }
        else{
            --it; // Move to the largest element less than x
            cout<<*it<<endl;
            a.erase(it); // Remove the found element
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}