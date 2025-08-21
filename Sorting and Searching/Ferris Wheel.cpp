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
    ll n,x;
    cin >> n>>x;
    vl v(n);
    loop(i,0,n-1)cin>>v[i];
    sort(all(v));
    ll i=0,j=n-1;
    ll count=0;
    while(i<j){
        if(v[i]+v[j]<=x){
            count++;
            i++;
            j--;
        }
        else{
            count++;
            j--;
        }
    }
    if(i==j)count++;
    cout<<count<<endl;
    return 0;
}