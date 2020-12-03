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

int main() {
    fast_cin();
    int t;
    cin >> t;
    for(int j=1; j<=t; j++) {
        int n;
        cin >> n;
        int max_so_far=INT_MIN,a[n],c=0;
        forn(i,n)   cin >> a[i];

        for(int i=0; i<n-1; i++) {
            if(a[i]>max_so_far && a[i]>a[i+1]) {
                c++;
            }

            max_so_far = max(max_so_far, a[i]);
        }

        if(n==1)    c=1;
        else {
            if(a[n-1] > max_so_far) c++;
        }

        printf("Case #%d: %d\n", j, c);
    }
    return 0;
}
