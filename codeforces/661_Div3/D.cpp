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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    v32 index(n), pos0,pos1;
    int count = 0;

    for (int i=0; i<n; i++) {
        // Search through all subsequences
        int j= pos0.size() + pos1.size();

        if (s[i]=='0') {
            if (pos1.empty()) {
                pos0.push_back(j);
            }
            else {
                j = pos1.back();
                pos1.pop_back();
                pos0.push_back(j);
            }
        }
        else {
            if (pos0.empty()) {
                pos1.push_back(j);
            }
            else {
                j = pos0.back();
                pos0.pop_back();
                pos1.push_back(j);
            }
        }

        index[i] = j;
    }

    cout << pos0.size() + pos1.size() << ln;
    for(auto it:index)  cout << it+1 << " ";
    cout << ln;
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