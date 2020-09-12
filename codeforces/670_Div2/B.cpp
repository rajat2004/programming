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

ll maxProd(const v64& v) {
    int n=v.size();
    ll prod=1;

    if (v[n-1]==0) {
        return 0;
    }

    if (v[n-1]<0) {
        for(int i=n-1; i>=n-5; i--)
            prod*=v[i];
        return prod;
    }

    int i=0,j=n-1;

    if (v[n-1]>0) {
        prod*=v[n-1];
        j--;
    }

    int k2=2;   // 2 pairs

    while(k2--) {
        ll left=v[i]*v[i+1], right=v[j]*v[j-1];
        if (left>right) {
            prod*=left;
            i+=2;
        }
        else {
            prod*=right;
            j-=2;
        }
    }
    return prod;
}

void solve() {
    int n;
    cin >> n;
    v64 v(n);
    input(v,n);

    sort(v.begin(), v.end());
    cout << maxProd(v) << ln;
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
