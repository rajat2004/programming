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

void ans(int t, int ans) {
    printf("Case #%d: %d\n", t, ans);
}

int getk(const v32& diff, int dopt) {
    int sum=0;
    for(int i=0; i<diff.size(); i++) {
        if (diff[i]%dopt==0)
            sum += diff[i]/dopt - 1;
        else
            sum += diff[i]/dopt;
    }
    return sum;
}

void solve(int t) {
    int n,k;
    cin >> n >> k;
    v32 v(n);
    input(v, n);

    if (k==1) {
        int mx=1, mx2=1;
        for(int i=1; i<n; i++) {
            int diff = v[i]-v[i-1];
            if (diff > mx) {
                mx2=mx;
                mx=diff;
            }
            else if (diff>mx2)
                mx2=diff;
        }

        if (mx/2 >= mx2) {
            int a = (mx%2==0) ? mx/2 : mx/2+1;
            ans(t, max(a, mx2));
        }
        else
            ans(t, mx2);
        return;
    }


    v32 diff(n-1);
    int max_diff=1;
    forn(i,n-1) {
        diff[i] = v[i+1]-v[i];
        max_diff = max(max_diff, diff[i]);
    }
    dbg(max_diff);
    int l=1,h=max_diff;

    while(l<=h) {
        int mid = (l+h)/2;
        int kcurr = getk(diff, mid);
        dbg(kcurr);

        if (kcurr == k) {
            ans(t, mid);
            return;
        }
        else if (kcurr < k) {
            h = mid-1;
        }
        else
            l = mid+1;
    }

    ans(t, h);

}

int main() {
    fast_cin();
    int T;
    cin >> T;
    forn(t,T) {
        solve(t+1);
    }
    return 0;
}
