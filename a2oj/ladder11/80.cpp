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

int main() {
    int n,m;
    fast_cin();
    FILE *in_ptr = fopen("input.txt", "r");
    FILE *out_ptr = fopen("output.txt", "w");
    fscanf(in_ptr, "%d", &n);
    fscanf(in_ptr, "%d", &m);
    fclose(in_ptr);
    int k = min(n,m);
    string s = "";

    n-=k;
    m-=k;
    if (m>0) {
        forn(i,m)
            s+="G";
    }

    forn(i,k)
        s+="BG";
    
    forn(i,n)
        s+="B";

    fprintf(out_ptr, "%s", s.c_str());
    fclose(out_ptr);
    return 0;
}