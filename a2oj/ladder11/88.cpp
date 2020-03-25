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

bool check_if_pass(int a[4][4], int r, int c) {
    int sum = a[r][c] + a[r][c+1] + a[r+1][c] + a[r+1][c+1];
    if(sum==2)
        return false;
    return true;
}

int main() {
    fast_cin();
    int a[4][4];
    char c;
    forn(i,4) {
        forn(j,4) {
            a[i][j]=0;
            cin >> c;
            if(c=='#')  a[i][j]=1;
        }
    }
    forn(i,3) {
        forn(j,3) {
            if(check_if_pass(a,i,j)) {
                cout << "YES" << ln;
                return 0;
            }
        }
    }
    cout << "NO" << ln;
    return 0;
}
