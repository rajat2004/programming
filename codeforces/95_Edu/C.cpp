#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned lluu;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zer ll(0)
#define printarr(arr,n) forn(i,n)   cout << arr[i] << " "
#define input(arr,n) forn(i,n)  cin >> arr[i]

int fun(int id, int p, const v32& b, vv32& dp, int n) {
    if (id>=n)  return 0;
    if (dp[id][p]!=-1)  return dp[id][p];

    if (p==0) {
        if (b[id]==1) {
            int v1 = fun(id+1, 1, b, dp, n);
            if (id<n-1) {
                if (b[id+1]==1)
                    v1 = min(v1, 1+fun(id+2, 1, b, dp, n));
                else
                    v1 = min(v1, fun(id+2, 1, b, dp, n));
            }
            return dp[id][p]=v1+1;
        }
        else {
            int v1=fun(id+1,1,b,dp,n);
            if (id<n-1) {
                if (b[id+1]==1)
                    v1 = min(v1, 1+fun(id+2, 1, b, dp, n));
                else
                    v1 = min(v1, fun(id+2, 1, b, dp, n));
            }
            return dp[id][p]=v1;
        }
    }
    else {
        return dp[id][p] = min(fun(id+1,0,b,dp,n),
                               fun(id+2,0,b,dp,n));
    }
}

void solve() {
    int n;
    cin >> n;
    v32 b(n);
    input(b,n);

    vv32 dp(n, v32(2,-1));


    cout << fun(0, 0, b, dp, n) << ln;
    // forn(i,n) {
    //     cout << dp[i][0] << " " << dp[i][1] << ln;
    // }
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
