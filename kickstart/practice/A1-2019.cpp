#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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

int main() {
    fast_cin();
    int T;
    cin >> T;
    forsn(t,1,T+1)
    {
        int n,p;
        cin >> n >> p;
        int a[n];
        forn(i,n)
            cin >> a[i];

        sort(a, a+n, greater<int>());
        ll min_train = INT_MAX;
        ll prefix_sum = 0;

        for(int i=0; i<p; i++) {
            prefix_sum+=a[i];
        }
        min_train = p*a[0] - prefix_sum;

        for(int i=1; i<=(n-p); i++) {
            prefix_sum += (a[i+p-1] - a[i-1]);
            min_train = min(min_train, p*a[i]-prefix_sum);
        }
        cout << "Case #" << t << ": " << min_train << ln;
    }

    return 0;
}
