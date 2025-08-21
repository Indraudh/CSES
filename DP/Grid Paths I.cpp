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
 
void solve(){
    ll n;
    cin >> n;
    vector<vl> grid(n,vl(n,1));
    loop(i,0,n-1){
        loop(j,0,n-1){
            char x;
            cin>>x;
            if(x=='*')grid[i][j]=0;
        }
    }
    vector<vl> dp(n,vl(n,0));
    if(grid[0][0]==0)cout<<0<<endl;
    else{
        loop(i,0,n-1){
            loop(j,0,n-1){
                if(i==0 && j==0)dp[i][j]=1;
                else if(grid[i][j]==0)dp[i][j]=0;
                else if(i==0)dp[i][j]=dp[i][j-1];
                else if(j==0)dp[i][j]=dp[i-1][j];
                else dp[i][j]=(dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
 
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}