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
    int n,m;
    cin >> n >> m;
    vector<string> mat(n, "");
    input(mat, n);

    vv32 dp(n, v32(m,1));

    vv32 upperleft(n, v32(m,1)), upperright(n, v32(m,1));
    vv32 downleft(n, v32(m,1)), downright(n, v32(m,1));


    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if (mat[i][j]==mat[i-1][j] &&  mat[i][j]==mat[i][j-1])
                upperleft[i][j] = min(upperleft[i-1][j], upperleft[i][j-1])+1;
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=m-2; j>=0; j--) {
            if (mat[i][j]==mat[i-1][j] && mat[i][j]==mat[i][j+1])
                upperright[i][j] = min(upperright[i-1][j], upperright[i][j+1]) + 1;
        }
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=1; j<m; j++) {
            if (mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i][j-1])
                downleft[i][j] = min(downleft[i+1][j], downleft[i][j-1]) + 1;
        }
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=m-2; j>=0; j--) {
            if (mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i][j+1])
                downright[i][j] = min(downright[i+1][j], downright[i][j+1]) + 1;
        }
    }

    int count=0;
    forn(i,n) {
        forn(j,m) {
            count += min({upperleft[i][j], upperright[i][j], downleft[i][j], downright[i][j]});
            // cout << count << " ";
        }
        // cout << ln;
    }
    cout << count << ln;
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
