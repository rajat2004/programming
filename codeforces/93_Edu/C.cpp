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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    v32 v(n), cum_sum(n+1,0);
    forn(i,n)
        v[i] = s[i]-'0';

    // cum_sum[0] = v[0];
    for(int i=1; i<=n; i++) {
        cum_sum[i] = cum_sum[i-1] + v[i-1];
    }

    map<int, ll> m;
    forsn(i,0,n+1) {
        // if (m.find(cum_sum[i]-i) != m.end())
        //     m[cum_sum[i]-i]++;
        // else
        //     m[cum_sum[i]-i] = 0;
        m[cum_sum[i]-i]++;
    }

    ll sum=0;
    for(auto p:m) {
        // cout << p.first << " " << p.second << ln;
        sum += (p.second * (p.second-1))/2;
    }
    cout << sum << ln;
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
