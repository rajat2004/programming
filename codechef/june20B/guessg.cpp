#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long lluu;
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

int lo, ro, le, re;

char query(int l, int r) {
    int m = (l+r)/2;
    cout << m << ln;
    char c;
    cin >> c;
    return c;
}

void update(char c, int q) {
    switch (c)
    {
    case 'L':
        if(q%2==0)  re = (le+re)/2-1;
        else        ro = (lo+ro)/2-1;
        break;

    case 'G':
        if(q%2==0)  le = (le+re)/2+1;
        else        lo = (lo+ro)/2+1;
        break;

    default:
        break;
    }
}

int main() {
    // fast_cin();
    int N;
    cin >> N;
    lo=1, ro=N, le=1, re=N;
    int q=1;
    char c;
    while(true) {
        if(q%2==0)  c = query(le, re);
        else c = query(lo, ro);

        if (c=='E') break;
        else update(c, q);

        q++;
    }
    return 0;
}
