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
    int n,m;
    cin >> n >> m;
    char a[n][m];
    forn(i,n) {
        forn(j,m)   cin >> a[i][j];
    }

    int c=0;
    forn(i,n) {
        forn(j,m) {
            if(a[i][j]=='P') {
                if(i!=0) {
                    if(a[i-1][j]=='W') {
                        a[i-1][j] = '.';
                        c++;
                    }
                }

                if (j!=0) {
                    if(a[i][j-1]=='W') {
                        a[i][j-1] = '.';
                        c++;
                    }
                }

                if (i!=(n-1)) {
                    if(a[i+1][j]=='W') {
                        a[i+1][j] = '.';
                        c++;
                    }
                }

                if (j!=(m-1)) {
                    if(a[i][j+1]=='W') {
                        a[i][j+1] = '.';
                        c++;
                    }
                }
            }
        }
    }

    cout << c << ln;
    return 0;
}
