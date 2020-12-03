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

void solve(int t) {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int a1 = a-c;
    int b1 = b-c;

    if (a1<0 || b1<0 || (a1+b1+c)>n) {
        printf("Case #%d: IMPOSSIBLE\n", t);
        return;
    }

    v32 v(n,-1);

    int left = n - (a1+b1+c);

    for (int i=0; i<a1; i++)
        v[i] = n-1;

    // for(int i=a1; i<a; i++)
    //     v[i] = n;

    // for(int i=a; i<(a+left); i++)
    //     v[i] = 1;

    if (c==1) {
        if (a1==0) {
            v[0] = n;
            for(int i=a; i<(a+left); i++)
                v[i] = 1;
        }
        else {
            for(int i=a1; i<(a1+left); i++)
                v[i] = 1;

            v[a1+left] = n;
        }
    }
    else {
        // c!=1
        v[a1] = n;
        for(int i=a1+1; i<(a1+1+left); i++)
            v[i] = 1;

        for(int i=(a1+1+left); i<(a1+1+left+c-1); i++)
            v[i] = n;
    }

    for (int i=n-b1; i<n; i++)
        v[i] = n-1;

    printf("Case #%d: ", t);
    forn(i,n)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    fast_cin();
    int T;
    cin >> T;
    forsn(t,1,T+1) {
        solve(t);
    }
    return 0;
}
