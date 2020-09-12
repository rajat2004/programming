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

void yes() { cout << "YES" << ln; }
void no() {cout << "NO" << ln;}

void solve() {
    int n,K;
    cin >> n >> K;
    string s;
    cin >> s;

    for(int i=0; i<K; i++) {
        int j=i, is01=-1;
        if (s[i]!='?')  is01=s[i]-'0';

        while(j<n) {
            if (s[j]!='?') {
                if (is01==-1)
                    is01 = s[j]-'0';
                else {
                    if (is01 != s[j]-'0') {
                        no();
                        return;
                    }
                }
            }

            j+=K;
        }

        if (s[i]=='?' && is01!=-1)
            s[i]='0'+is01;
    }

    // dbg(s);
    int c0=0,c1=0;

    for(int i=0; i<K; i++) {
        if (s[i]=='0')  c0++;
        else if (s[i]=='1')  c1++;
    }

    if (c0>K/2 || c1>K/2) {
        no(); return;
    }

    yes();

}

int main() {
    // fast_cin();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
