// Question - https://www.geeksforgeeks.org/find-minimum-possible-size-of-array-with-given-rules-for-removal/

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

int minSize(const v32 &v, int low, int high, const int k, vv32 &dp) {
    if (high-low+1 < 3)
        return high-low+1;

    if (dp[low][high]!=-1)
        return dp[low][high];

    int res = 1 + minSize(v, low+1, high, k, dp);

    for(int i=low+1; i<=high; i++) {
        if ((v[i]-v[low])!=k)
            continue;

        for(int j=i+1; j<=high; j++) {
            if ((v[j]-v[i])==k
                && minSize(v, low+1, i-1, k, dp)==0
                && minSize(v, i+1, j-1, k, dp)==0)
                res = min(res, minSize(v, j+1, high, k, dp));
        }
    }

    return dp[low][high] = res;
}

void solve() {
    int n,k;
    cin >> n >> k;
    v32 v(n);
    input(v,n);

    vv32 dp(n, v32(n, -1));

    cout << minSize(v, 0, n-1, k, dp) << endl;
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
