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

vector<lluu> sq_req;
vector<lluu> tot_sq_req;


void solve() {
    lluu x;
    cin >> x;

    auto it = lower_bound(tot_sq_req.begin(), tot_sq_req.end(), x);

    if (*it==x) {
        cout << (it-tot_sq_req.begin())+1 << ln;
    }
    else {
        cout << (it-tot_sq_req.begin()) << ln;
    }
}

void generate() {
    sq_req.clear();
    tot_sq_req.clear();

    sq_req.push_back(1);
    lluu curr=1, sq_size=2;

    while(true) {
        lluu new_size = curr*2 + sq_size*sq_size;
        if (new_size > INF)
            break;
        sq_req.push_back(new_size);
        curr = new_size;
        sq_size*=2;
    }

    // printarr(sq_req, sq_req.size());
    // cout << ln;
    tot_sq_req.push_back(1);

    for(int i=1; i<sq_req.size(); i++)
        tot_sq_req.push_back(sq_req[i]+tot_sq_req[i-1]);

    // printarr(tot_sq_req, tot_sq_req.size());
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    generate();
    while(t--) {
        solve();
    }
    return 0;
}
