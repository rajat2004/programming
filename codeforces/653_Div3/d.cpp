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

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int a,tmp,mx=0,mx_idx;
        map<int,int> m;
        forn(i,n) {
            cin >> a;
            tmp = a%k;
            if(tmp!=0) {
                tmp = k - tmp;
                m[tmp]++;
                mx=max(mx, m[tmp]);
            }
        }

        ll ans = 0;
        for(auto [key, val] : m) {
            if(val==mx)
                ans = k*1ll*(val-1) + key + 1;
        }
        cout << ans << ln;
    }
    return 0;
}