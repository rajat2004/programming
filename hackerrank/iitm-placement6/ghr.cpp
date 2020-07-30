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

bool ghr(string a, string b) {
    int a_len = a.length(), b_len = b.length();

    if(a == b)
        return true;

    string a1 = a.substr(0, a_len/2);
    string a2 = a.substr(a_len/2);

    string b1 = b.substr(0, b_len/2);
    string b2 = b.substr(b_len/2);

    // cout << a1 << " " << a2 << "  " << b1 << " " << b2 << ln;

    if(a1.length()!=a2.length() || b1.length()!=b2.length())
        return false;

    bool ans = ((ghr(a1,b1) && ghr(a2,b2)) || (ghr(a1,b2) && ghr(a2,b1)));
    // dbg(ans);
    return ans;
}

int main() {
    fast_cin();
    int n,m;
    string a,b;
    cin >> n >> a >> m >> b;
    if(ghr(a,b))  cout << "YES" << ln;
    else  cout << "NO" << ln;
    return 0;
}
