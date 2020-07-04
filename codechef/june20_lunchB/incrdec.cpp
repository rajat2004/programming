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

void print(v32 v) {
    forn(i, v.size())   cout << v[i] << " ";
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    int tot_size = 2e5+1;
    int count[tot_size];
    while(t--) {
        memset(count, 0, tot_size*sizeof(int));
        int n,a;
        cin >> n;
        bool flag = false;
        v32 v1, v2;

        forn(i,n) {
            cin >> a;
            count[a]++;
            if(count[a] == 3) flag = true;

            if(count[a]==2) v2.pb(a);
            else            v1.pb(a);
        }

        if(flag)    cout << "NO" << ln;
        else {
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end(), greater<int>());

            if(v2.size()>0 && v1[v1.size()-1]==v2[0])  cout << "NO" << ln;
            else {
                cout << "YES" << ln;
                print(v1);
                print(v2);
                cout << ln;
            }
        }

    }
    return 0;
}
