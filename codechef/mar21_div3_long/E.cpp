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
#define yes() cout << "Yes" << ln
#define no() cout << "No" << ln



void solve() {
    ll n,e,h,a,b,c;

    cin >> n >> e >> h >> a >> b >> c;

    ll min_price = INF, MAX_X=min(n, 2*e + h - 3*n), MAX_Y=min(n, e + h - 2*n);

    if (MAX_X<0 || MAX_Y<0) {
        cout << -1 << ln;
        return;
    }

    auto valid = [&](const ll& x, const ll& y) -> bool {
        if (x+y > n)
            return false;

        return ((n+x-y) <= e) && ((n-x + 2*y) <= h);
    };

    auto calc_price = [&](const ll& x, const ll& y) -> ll {
        return x*(a-c) + y*(b-c) + n*c;
    };

    auto check_update = [&](const ll& x, const ll& y) {
        if (valid(x, y))
            min_price = min(min_price, calc_price(x, y));
    };

    // for(ll x=0; x<=MAX_X; x++) {
    //     for(ll y=0; y<=MAX_Y; y++) {
    //         if (x+y > n)
    //             break;

    //         if ((n+x-y > e) || (n-x + 2*y) > h)
    //             continue;

    //         ll p = x*(a-c) + y*(b-c) + n*c;
    //     //     dbg(x);
    //     //     dbg(y);

    //     //    dbg(p);

    //         min_price = min(min_price, p);
    //     }
    // }

    for(ll x=0; x<=MAX_X; x++) {
        for(ll y=0; y<=MAX_Y; y++) {
            check_update(x, y);
        }
    }

    // Check for x=0
    // for(ll y=0; y<=MAX_Y; y++) {
    //     check_update(0, y);
    // }

    // // Check for y=0
    // for(ll x=0; x<=MAX_X; x++) {
    //     check_update(x, 0);
    // }

    // // x=MAX_X
    // for(ll y=0; y<=n-MAX_X; y++) {
    //     check_update(MAX_X, y);
    // }

    // // y=MAX_Y
    // for(ll x=0; x<=n-MAX_Y; x++) {
    //     check_update(x, MAX_Y);
    // }

    // // On line x+y=n
    // for(ll x=MAX_X; x>=0; x--) {
    //     check_update(x, n-x);
    // }

    cout << min_price << ln;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
