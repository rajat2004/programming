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

    int sumo=0, sume=0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if (i%2==0) sume+=v[i];
        else        sumo+=v[i];
    }

    if (sume==sumo) {
        cout << n << ln;
        printarr(v, n);
        cout << ln;
        return;
    }

    vector<bool> keep(n, true);
    int i=0,j;
    for(i=0; i<n; i++) {
        if (v[i]==1)
            break;
    }
    j=i+1;

    while(i<n && j<n) {
        while(j<n && v[j]==0)
            j++;

        if (j==n) {
            keep[i] = false;
            break;
        }

        if ((j-i)%2==0) {
            keep[j-1] = false;
            // i=j;
            // j=i+1;
        }
        // else {
        //     i=j;
        //     j++;
        // }

        i=j+1;
        while(i<n && v[i]==0)
            i++;
        if (i==n)   break;
        j=i+1;
        if (j==n)   keep[i] = false;
    }
    int tot = 0;
    for(int t=0; t<n; t++)
        tot += keep[t];

    cout << tot << ln;
    for(int t=0; t<n; t++) {
        if (keep[t])
            cout << v[t] << " ";
    }
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
