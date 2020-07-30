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

void err() {
    cout << "NO" << ln;
}
void success() {
    cout << "YES" << ln;
}

void solve() {
    string s1,s2;
    cin >> s1 >> s2;

    int MAX_CHARS = 256;

    int m=s1.length(), n=s2.length();

    if(m!=n) {
        err();
        return;
    }

    int map[MAX_CHARS];
    memset(map, -1, MAX_CHARS*sizeof(int));

    bool marked[MAX_CHARS];
    memset(marked, false, MAX_CHARS*sizeof(bool));

    forn(i,m) {
        if(map[s1[i]]==-1) {
            if(marked[s2[i]]) {
                err();
                return;
            }

            map[s1[i]] = s2[i];
            marked[s2[i]] = true;
        }
        else if (map[s1[i]]!=s2[i]) {
            err();
            return;
        }
    }

    success();
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
