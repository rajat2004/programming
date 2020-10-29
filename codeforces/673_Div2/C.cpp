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

const int MAXN=3e5+5;

v32 diff(MAXN), last_id(MAXN), res(MAXN);

void solve() {
    int n;
    cin >> n;
    v32 v(n);
    input(v,n);

    // v32 diff(n+1, INT_MIN), last_id(n+1, -1);

    for(int i=0; i<=n; i++) {
        diff[i]=INT_MIN;
        last_id[i] = -1;
        res[i] = -1;
    }

    for(int i=0; i<n; i++) {
        diff[v[i]] = max(diff[v[i]], i-last_id[v[i]]);
        last_id[v[i]] = i;
    }

    // v32 res(n, -1);

    for(int i=1; i<=n; i++) {
        diff[i] = max(diff[i], n-last_id[i]);

        if (diff[i]<=n) {
            int j=diff[i]-1;
            while(j<n) {
                if (res[j]!=-1)
                    break;

                res[j] = i;
                j++;
            }
        }
    }

    printarr(res, n);
    cout << ln;
}

int main() {
    fast_cin();
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
