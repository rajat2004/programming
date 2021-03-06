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

ll sx(ll n) {
    ll sum = 0;
    while(n>0) {
        sum += n%10;
        n/=10;
    }
    return sum;
}

ll power(ll x, unsigned int a) {
    ll temp;
    if (a == 0)
        return 1;

    temp = power(x, a / 2);
    if ((a % 2) == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main() {
    fast_cin();
    ll b,c,x;
    unsigned int a;
    cin >> a >> b >> c;
    v64 v;
    forsn(x, 1, 82) {
        ll val = b * power(x, a) + c;

        if (sx(val)==x && val>0 && val<1e9)
            v.pb(val);
    }
    sort(v.begin(), v.end());
    cout << v.size() << ln;
    if (v.size() > 0) {
        cout << v[0];
        forsn(i, 1, v.size()) cout << " " << v[i];
        cout << ln;
    }
    return 0;
}
