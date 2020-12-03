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

void solve(int t) {
    int N,K,P;
    cin >> N >> K >> P;
    vv32 vst(N, v32(K));
    forn(i,N) {
        forn(j,K)
            cin >> vst[i][j];
    }

    vv32 sum(N+1, v32(K+1, 0));
    forsn(i,1,N+1) {
        forn(j,K) {
            sum[i][j+1] = sum[i][j] + vst[i-1][j];
            // cout << sum[i][j+1] << " ";
        }
        // cout << ln;
    }

    vv32 dp(N+1, v32(P+1, 0));

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=P; j++) {
            int max_sum=INT_MIN;
            for(int a=0; a<=min(j,K); a++) {
                // a from ith stack, rest from prev i-1 stacks
                max_sum = max(max_sum, sum[i][a] + dp[i-1][j-a]);
            }
            dp[i][j] = max_sum;
            // cout << dp[i][j] << " ";
        }
        // cout << ln;
    }

    printf("Case #%d: %d\n", t, dp[N][P]);
}

int main() {
    // fast_cin();
    int T;
    cin >> T;
    forn(t,T) {
        solve(t+1);
    }
    return 0;
}
