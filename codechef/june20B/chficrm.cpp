#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long lluu;
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
    int t;
    cin >> t;
    while(t--) {
        int c5=0, c10=0, c15=0;
        int n,a;
        cin >> n;
        bool f = true;

        forn(i,n) {
            cin >> a;
            if(f==false)    continue;

            switch (a) {
            case 5:
                c5++;
                break;

            case 10:
                if(c5<=0)   f = false;
                else {
                    c5--;
                    c10++;
                }
                break;

            case 15:
                if (c10>0) {
                    c10--;
                    c15++;
                }
                else {
                    if (c5>=2) {
                        c5-=2;
                        c15++;
                    }
                    else f = false;
                }
                break;
            }
        }

        if (f)  cout << "YES" << ln;
        else    cout << "NO" << ln;
    }
    return 0;
}
