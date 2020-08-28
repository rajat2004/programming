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

p32 run(int n, int m) {
    int same=0,diff=0;
    char last='1', curr;
    n--;
    int i=1;
    while(n>0 && m>0) {
        if (i%2!=0) {
            diff++;
            if (last=='1') {
                last='0';
                m--;
            }
            else {
                last='1';
                n--;
            }
        }
        else {
            same++;
            if (last=='1') {
                n--;
            }
            else {
                m--;
            }
        }
        i++;
    }

    if (n>0) {
        if (last=='1') {
            same+=n;
        }
        else {
            diff++;
            n--;
            same+=n;
        }
    }
    else {
        if (last=='0') {
            same+=m;
        }
        else {
            diff++;
            m--;
            same+=m;
        }
    }
    return {same, diff};
}

void solve() {
    int n,m;
    cin >> n >> m;
    p32 p1 = run(n,m);
    p32 p2 = run(m,n);
    if (p1.first > p2.first) {
        cout << p1.first << " " << p1.second << ln;
    }
    else
        cout << p2.first << " " << p2.second << ln;
}

int main() {
    fast_cin();
    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
