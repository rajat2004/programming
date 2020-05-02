#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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

void print(v32 v) {
    cout << v.size();
    forn(i,v.size()) cout << " " << v[i];
    cout << ln;
}

int main() {
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    int cn=0;
    forn(i,n) {
        cin >> arr[i];
        if(arr[i]<0)
            cn++;
    }
    sort(arr, arr+n);
    v32 v1,v2,v3;

    v1.pb(arr[0]);
    v3.pb(arr[cn]);
    cn--;
    if (cn%2==0) {
        forsn(i,1,cn+1) v2.pb(arr[i]);
    }
    else {
        v3.pb(arr[1]);
        forsn(i,2,cn+1) v2.pb(arr[i]);
    }
    forsn(i,cn+2,n) v2.pb(arr[i]);

    print(v1);
    print(v2);
    print(v3);
    return 0;
}
