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

int median(const v32& v, int n, int x) {
    auto low = lower_bound(v.begin(), v.end(), x);
    auto high = upper_bound(v.begin(), v.end(), x);

    int count=high-low, low_idx=low-v.begin(), high_idx=high-v.begin();
    int diff1 = low_idx - (n+1)/2 + 1;
    int diff2 = (n+1)/2-high_idx;
    // dbg(diff1);
    // dbg(diff2);
    if (diff1>0) {
        if (n%2==0)
            return 2*diff1-1;
        else
            return 2*diff1;
    }
    if (diff2>0) {
        if (n%2==0)
            return 2*diff2;
        else
            return 2*diff2-1;
    }
        // return 2*diff2;

    return 0;
}

void solve() {
    int n,x;
    cin >> n >> x;
    v32 v(n);
    input(v,n);
    sort(v.begin(), v.end());
    if (v[(n+1)/2 - 1] == x)
        cout << 0 << ln;
    else {
        int res=0;
        if (!binary_search(v.begin(), v.end(), x)) {
            v.push_back(x);
            sort(v.begin(), v.end());
            n++;
            res=1;
            if (v[(n+1)/2 - 1] == x) {
                // cout << "Here" << ln;
                cout << 1 << ln;
                return;
            }
        }
        res += median(v,n,x);
        cout << res << ln;
    }
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
