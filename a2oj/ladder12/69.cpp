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

bool is_prime(int n) {
    if (n<=1)
        return false;
    if(n<=3)
        return true;

    if(n%2==0 || n%3==0)
        return false;

    for(int i=5; i*i<=n; i+=6) {
        if (n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}

int main() {
    fast_cin();
    int n;
    cin >> n;
    for(int i=2; i<(1e7+1); i++) {
        if(is_prime(i)) {
            cout << i << " ";
            n--;
        }
        if(n==0)
            break;
    }
    return 0;
}
