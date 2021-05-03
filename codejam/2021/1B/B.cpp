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

vector<lluu> fib;

void solve(int pid) {
    int n, a, b;
    cin >> n >> a >> b;
    v32 u(n);
    input(u, n);

    lluu req = 0;
    forn(i,n) {
        req += fib[i+1] * u[i];
    }

    // dbg(req);

    auto it = lower_bound(fib.begin(), fib.end(), req);

    printf("Case #%d: %d\n", pid, it-fib.begin());
}

int main() {
    fast_cin();

    fib = vector<lluu>(60);
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<fib.size(); i++)
        fib[i] = fib[i-1] + fib[i-2];

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t;
    int id = 1;
    while(t--) {
        solve(id);
        id++;
    }
    return 0;
}
