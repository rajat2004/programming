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
    int n,m;
    cin >> n >> m;
    vv32 mat(n, v32(m));
    forn(i,n) {
        forn(j,m) {
            cin >> mat[i][j];
        }
    }

    ll res=0;
    int rowl = (n%2==0) ? n/2-1 : n/2;
    int coll = (m%2==0) ? m/2-1 : m/2;

    for(int i=0; i<=rowl; i++) {
        for(int j=0; j<=coll; j++) {
            v32 v{mat[i][j], mat[i][m-j-1], mat[n-i-1][j], mat[n-i-1][m-j-1]};
            sort(v.begin(), v.end());
            ll sum = (v[1]+v[2])/2;

            res += abs(sum-mat[i][j]);

            if (i!=(n-i-1))
                res+=abs(sum-mat[n-i-1][j]);
            if (j!=(m-j-1))
                res+= abs(sum-mat[i][m-j-1]);
            if (i!=(n-i-1) && j!=(m-j-1))
                res+=abs(sum-mat[n-i-1][m-j-1]);
        }
    }

    cout << res << ln;
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
