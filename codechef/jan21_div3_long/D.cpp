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
#define printpair(p) cout << p.first << " " << p.second << endl

p32 getCollPoint(p32 p, int dirX, int dirY, int N) {
    auto getSteps = [](int lim, int x, int dir) {
        return (lim-x)/dir;
    };

    auto getLim = [N](int dir) {
        return (dir==1) ? N : 0;
    };

    int xlim = getLim(dirX), ylim = getLim(dirY);
    int a = min(getSteps(xlim, p.first, dirX), getSteps(ylim, p.second, dirY));

    return {p.first + a*dirX, p.second + a*dirY};
}

void solve() {
    ll n,k,x,y;
    cin >> n >> k >> x >> y;

    if (x==y) {
        printpair(make_pair(n, n));
        return;
    }

    auto curr = getCollPoint({x, y}, -1, -1, n);
    int dirX=1, dirY=1;

    forn(i, k%4) {
        auto next = getCollPoint(curr, dirX, dirY, n);
        int x = next.first, y = next.second;

        // Right, Left wall
        if (x==n || x==0) {
            dirX *= -1;
        }
        // Top, bottom
        else if (y==0 || y==n) {
            dirY *= -1;
        }

        curr = next;
    }

    printpair(curr);
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
