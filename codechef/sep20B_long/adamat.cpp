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
    int count=0;

    vv32 mat(n, v32(n));
    forn(i,n) {
        forn(j,n)
            cin >> mat[i][j];
    }

    // int id=n;
    bool flipped=false;

    for(int id=n; id>=1; id--) {
        // int curr_val = id*id;
        int curr_val = (id-1)*n + id;
        // dbg(curr_val);
        if (flipped) {
            // cout << "Flipped" << ln;
            for(int j=id-1; j>=0; j--) {
                if (mat[j][id-1]!=curr_val) {
                    count++;
                    flipped = !flipped;
                    break;
                }
                curr_val--;
            }
        }
        else {
            // cout << "Not flipped" << ln;
            for(int i=id-1; i>=0; i--) {
                if (mat[id-1][i]!=curr_val) {
                    count++;
                    flipped = !flipped;
                    break;
                }
                curr_val--;
            }
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
