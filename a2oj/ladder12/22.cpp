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

void gen_row(int row, int n) {
    int spaces = (n-row)*2;
    while(spaces--) cout << " ";

    cout << "0";

    for(int i=1; i<=row; i++)   cout << " " << i;
    for(int i=row-1; i>=0; i--) cout << " " << i;

    cout << ln;
}

int main() {
    fast_cin();
    int n;
    cin >> n;
    for(int row=0; row<=n; row++) {
        gen_row(row, n);
    }

    for(int row=n-1; row>=0; row--) {
        gen_row(row, n);
    }
    return 0;
}
