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

ll sum(int a[], int l, int r) {
    ll sum = 0;
    for(int i=l; i<=r; i++)
        sum += a[i];
    return sum;
}

int main() {
    fast_cin();
    int n,m;
    cin >> n;
    ll v[n+1], u[n+1];
    v[0] = 0;
    u[0] = 0;
    forsn(i,1,n+1){
        cin >> v[i];
        u[i] = v[i];
    }
    sort(u, u+n+1);
    for(int i=1; i<=n; i++) {
        v[i] += v[i-1];
        u[i] += u[i-1];
    }
    cin >> m;
    int t,l,r;

    while(m--) {
        cin >> t >> l >> r;

        if(t==1) {
            cout << v[r] - v[l-1] << ln;
        }
        else {
            cout << u[r] - u[l-1] << ln;
        }
    }
    return 0;
}
