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
    ll t,sx,sy,ex,ey;
    cin >> t >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;
    ll x = ex - sx;
    ll y = ey - sy;
    forn(i,t) {
        if(x==0 && y==0) {
            cout << i << ln;
            return 0;
        }

        if(s[i]=='E' || s[i]=='W') {
            if(s[i]=='E' && x>0) {
                x--;
            }
            else if (s[i]=='W' && x<0) {
                x++;
            }
        }

        if(s[i]=='N' || s[i]=='S') {
            if(s[i]=='N' && y>0) {
                y--;
            }
            else if(s[i]=='S' && y<0) {
                y++;
            }
        }
    }
    if(x==0 && y==0)    cout << t << ln;
    else cout << -1 << ln;
    return 0;
}
