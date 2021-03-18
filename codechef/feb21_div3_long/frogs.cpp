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

struct Frog {
    int w, pos, l;

    Frog(int w, int i, int l)
    : w(w), pos(i), l(l)
    {}
};

void solve() {
    int n;
    cin >> n;

    v32 W(n), L(n);
    input(W, n);
    input(L, n);

    vector<Frog> vf;
    forn(i,n) {
        vf.push_back(Frog(W[i], i+1, L[i]));
    }

    sort(vf.begin(), vf.end(), [](const Frog& f1, const Frog& f2) {
        return f1.w < f2.w;
    });

    int res=0, curr_pos=vf[0].pos;

    for(int i=1; i<n; i++) {
        int kicks=0, new_pos = vf[i].pos;

        if (new_pos < curr_pos) {
            kicks = ceil( (curr_pos - vf[i].pos) / (vf[i].l*1.0f) );
            new_pos = vf[i].pos + kicks*vf[i].l;
        }

        if (new_pos == curr_pos) {
            new_pos += vf[i].l;
            kicks++;
        }

        curr_pos = new_pos;
        res += kicks;
    }

    cout << res << endl;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
