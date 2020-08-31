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

ll try0(ll r, ll g, ll b) {
    return (r/3 + g/3 + b/3);
}

ll try1(ll r, ll g, ll b) {
    if (r<1 || g<1 || b<1)  return 0;
    return ( (r-1)/3 + (g-1)/3 + (b-1)/3 + 1 );
}

ll try2(ll r, ll g, ll b) {
    if (r<2 || g<2 || b<2)  return 0;
    return ( (r-2)/3 + (g-2)/3 + (b-2)/3 + 2 );
}

void solve() {
    ll r,g,b;
    cin >> r >> g >> b;

    ll t0 = try0(r,g,b);
    ll t1 = try1(r,g,b);
    ll t2 = try2(r,g,b);

    cout << max(max(t0,t1), t2) << ln;
}

int main() {
    fast_cin();
    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
