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

// Returns length of the longest AP subset in a given set
int lengthOfLongestAP(const v32& a, int n)
{
    if (n <= 2)  return n;
    int llap=2, curr=2, d=a[1]-a[0];

    for (int i=2; i<n; i++) {
        if (a[i]-a[i-1] != d) {
            llap = max(llap, curr);
            curr = 2;
            d = a[i]-a[i-1];
            continue;
        }

        curr++;
        llap = max(llap, curr);
    }

    return llap;
}

void solve(int t) {
    int n;
    cin >> n;
    v32 v(n);
    input(v, n);

    // sort(v.begin(), v.end());

    int count=lengthOfLongestAP(v, n);
    printf("Case #%d: %d\n", t, count);
}

int main() {
    fast_cin();
    int T;
    cin >> T;
    forn(t, T) {
        solve(t);
    }
    return 0;
}