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

bool comp(p32 p1, p32 p2) {
    if (p1.first != p2.first)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}

int main() {
    fast_cin();
    int n,k,p,t;
    cin >> n >> k;
    vector<p32> v;
    forn(i,n) {
        cin >> p >> t;
        v.pb(make_pair(p,t));
    }
    sort(v.begin(), v.end(), comp);
    // forn(i,n) {
    //     cout << v[i].first << " " << v[i].second << ln;
    // }
    int c=1;
    p32 pk=v[k-1];
    for(int i=k-2; i>=0; i--) {
        if(v[i]==pk)
            c++;
        else
            break;
    }
    for(int i=k; i<n; i++) {
        if(v[i]==pk)
            c++;
        else
            break;
    }
    cout << c << ln;
    return 0;
}
