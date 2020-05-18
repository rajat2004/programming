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
    fast_cin();
    string s1,s2;
    cin >> s1 >> s2;
    int c1[2]={0,0};
    int c2[3]={0,0,0};
    forn(i, s1.length()) {
        if(s1[i]=='+')  c1[0]++;
        else            c1[1]++;
    }

    forn(i, s2.length()) {
        if(s2[i]=='+')  c2[0]++;
        else if(s2[i]=='-') c2[1]++;
        else            c2[2]++;
    }

    int x1=c1[0]-c1[1];
    int x2 = c2[0]-c2[1];
    int diff = abs(x1-x2);

    if(c2[2]==0) {
        if(diff==0) cout << 1 << ln;
        else        cout << 0 << ln;
        return 0;
    }

    if(diff > c2[2]) {
        cout << 0 << ln;
        return 0;
    }

    int a,b;
    // a+b = c2[2]
    // a-b = diff
    double prob = 0;
    for(a=0; a<=c2[2]; a++) {
        b = c2[2] - a;
        if((a-b)==diff) {
            ll nCa = 1;
            rforsn(i, c2[2], c2[2]-a+1) nCa*=i;
            forsn(i,1,a+1)  nCa/=i;

            prob += ((double)nCa) * pow(0.5, c2[2]);
        }
        else continue;
    }
    cout << fixed << setprecision(9) << prob << ln;
    return 0;
}
