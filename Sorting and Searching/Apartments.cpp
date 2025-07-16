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
    ll n,m,k;
    cin >> n >> m >> k;
    vl a(n),b(m);
    loop(i,0,n-1)cin>>a[i];
    loop(i,0,m-1)cin>>b[i];
    sort(all(a));
    sort(all(b));
    ll i=0,j=0;
    ll count=0;
    while(i<n && j<m){
        if((a[i]-b[j])>k)j++;
        else if((b[j]-a[i])>k)i++;
        else{
            i++;
            j++;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}