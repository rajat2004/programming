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
    v32 v(n);
    input(v,n);
    ll count=0;
    int i=0,j=1;

    while(i<n && j<n) {
        // dbg(i);
        // dbg(j);
        // Find pos number
        while(i<n && v[i]<=0)
            i++;

        // Find -ve number
        j=i+1;
        while(j<n && v[j]>=0)
            j++;

        if (i>=n || j>=n)   break;
        if (abs(v[i]) > abs(v[j])) {
            // count += abs(v[j]);
            v[i] -= abs(v[j]);
            v[j] = 0;
        }
        else {
            // count += abs(v[i]);
            v[j] += abs(v[i]);
            v[i] = 0;
            i++;
        }
    }
    i=0; j=1;
    while(i<n && j<n) {
        // Find neg number
        while(i<n && v[i]>=0)
            i++;

        // Find +ve number
        j=i+1;
        while(j<n && v[j]<=0)
            j++;

        if (i>=n || j>=n)   break;
        if (abs(v[i]) > abs(v[j])) {
            count += abs(v[j]);
            v[i] += abs(v[j]);
            v[j] = 0;
        }
        else {
            count += abs(v[i]);
            v[j] -= abs(v[i]);
            v[i] = 0;
            i++;
        }
    }

    cout << count << ln;
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
