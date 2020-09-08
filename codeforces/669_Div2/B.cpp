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
    v32 v(n);
    input(v,n);
    sort(v.begin(), v.end(), greater<int>());

    v32 res;
    vector<bool> used(n, false);

    res.push_back(v[0]);
    used[0] = true;
    int req=n-1, max_gcd=v[0];

    while(req>0) {
        int curr_gcd=INT_MIN, id;
        for(int i=1; i<n; i++) {
            if (used[i])    continue;

            int tmp=__gcd(max_gcd, v[i]);
            if (tmp > curr_gcd) {
                curr_gcd = tmp;
                id = i;
            }
        }
        res.push_back(v[id]);
        used[id] = true;
        req--;
        max_gcd = curr_gcd;
        if (max_gcd == 1)   break;
    }

    if (req>0) {
        for (int i=0; i<n; i++) {
            if (!used[i])
                res.push_back(v[i]);
        }
    }

    printarr(res, n);
    cout << ln;
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
