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

void yes() {
    cout << "YES" << ln;
}
void no() {
    cout << "NO" << ln;
}

void solve() {
    int n;
    cin >> n;
    int even=0,odd=0,tmp;
    unordered_map<int,int> mp_even, mp_odd;
    forn(i,n) {
        cin >> tmp;
        if(tmp%2==0) {
            even++;
            mp_even[tmp]++;
        }
        else {
            odd++;
            mp_odd[tmp]++;
        }
    }

    if (even%2==0 && odd%2==0) {
        yes();
    }
    else if (even%2!=0 && odd%2!=0) {
        for (auto it:mp_even) {
            int val = it.first;
            if (mp_odd.find(val-1)!=mp_odd.end() || mp_odd.find(val+1)!=mp_odd.end()) {
                yes();
                return;
            }
        }
        no();
    }
    else {
        no();
    }
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
