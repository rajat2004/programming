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

void fillarr(vector<int> &res, int k, int n) {
    if (k==3 && n!=3) {
        res[0]=1, res[1]=2, res[2]=-3, res[3]=4;
        for(int x=5; x<=n; x++)
            res[x-1] = -x;

        // printarr(res, n);
        // cout << ln;
        return;
    }

    int sum = 0, lim1=(k*(k+1))/2, lim2 = ((k+1)*(k+2))/2;
    bool pos = true;

    int x = 1;

    while(x<=n) {
        if (pos) {
            res[x-1] = x;
            sum += x;

            if (2*sum>lim1 && 2*sum<=lim2)
                pos = false;
        }
        else {
            res[x-1] = -x;
        }

        x++;
    }
}

void solve() {
    int n,k;
    cin >> n >> k;

    v32 res(n, -1);

    bool reverse = false;

    if (k>n/2) {
        k = n-k;
        reverse = true;
    }

    fillarr(res, k, n);

    if (reverse) {
        forn(i,n)
            res[i] = -1 * res[i];
    }

    printarr(res, n);
    return;

    // if (k==3 && n!=3) {
    //     res[0]=1, res[1]=2, res[2]=-3, res[3]=4;
    //     for(int x=5; x<=n; x++)
    //         res[x-1] = -x;

    //     printarr(res, n);
    //     cout << ln;
    //     return;
    // }

    // int sum = 0, lim1=(k*(k+1))/2, lim2 = ((k+1)*(k+2))/2;
    // bool pos = true;

    // int x = 1;

    // while(x<=n) {
    //     if (pos) {
    //         res[x-1] = x;
    //         sum += x;

    //         if (2*sum>lim1 && 2*sum<=lim2)
    //             pos = false;
    //     }
    //     else {
    //         res[x-1] = -x;
    //     }

    //     x++;
    // }

    // printarr(res, n);
    // cout << ln;
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
