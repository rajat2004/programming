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

ll next(ll n) {
    ll res = 0;
    ll mul = 1;
    ll mod;
    while(n) {
        mod = n%10;
        if(mod <= 4)        res+=4*mul;
        else if (mod<=7)    res+=7*mul;
        else {
            res+=4*mul;
            n+=(14-mod);
        }
        mul*=10;
        n/=10;
    }
    // dbg(res);
    return res;

}

int main() {
    fast_cin();
    ll l,r;
    cin >> l >> r;
    ll sum=0, cnext=next(l),last_next;

    if (cnext >= r) sum=(r-l+1)*cnext;
    else {
        sum += (cnext-l+1)*cnext;

        while (true)
        {
            last_next = cnext;
            if (last_next > r) break;
            cnext = next(cnext+1);
            if (cnext >= r) {
                sum += (r-last_next)*cnext;
                break;
            }
            else sum+=(cnext-last_next)*cnext;
            // dbg(sum);
        }

    }

    cout << sum << ln;

    return 0;
}
