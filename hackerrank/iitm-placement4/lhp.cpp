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

bool isPerfectSquare(long double x)
{
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}

bool isProduct(int num)
{
    int cnt = 0;

    for (int i = 2; cnt < 2 && i * i <= num; ++i) {
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
    }

    if (num > 1)
        ++cnt;

    return cnt == 2;
}

bool fun(int n) {
    return (isProduct(n) && !isPerfectSquare(n));
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        if (fun(n)) {
            cout << n << ln;
            continue;
        }

        int less_n, more_n;

        // Find <n
        for(int i=n-1; i>=0; i--) {
            if(fun(i)) {
                less_n = i;
                break;
            }
        }

        for(int i=n+1; i<=INT_MAX; i++) {
            if(fun(i)) {
                more_n = i;
                break;
            }
        }

        if((n-less_n) <= (more_n-n))
            cout << less_n << ln;
        else
            cout << more_n << ln;
    }
    return 0;
}
