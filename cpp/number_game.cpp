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
#define yes() cout << "Yes" << ln
#define no() cout << "No" << ln

int choice(const v32 &v, vector<bool> &used, int size) {
    int maxgcd=INT_MIN, id1, id2;
    for(int i=0; i<size; i++) {
        if (!used[i]) {
            for(int j=i+1; j<size; j++) {
                if (!used[j]) {
                    int g = __gcd(v[i], v[j]);
                    if (g > maxgcd) {
                        maxgcd = g;
                        id1 = i;
                        id2 = j;
                    }
                }
            }
        }
    }

    used[id1] = true;
    used[id2] = true;
    return maxgcd;
}

void solve() {
    int n;
    cin >> n;
    int size = 2*n;
    v32 v(size);

    input(v, size);

    int round=n, tot=0;
    vector<bool> used(size, false);

    while(round > 0) {
        auto pick = choice(v, used, size);
        // cout << pick << endl;
        tot += pick * round;
        round--;
    }

    cout << tot << endl;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
