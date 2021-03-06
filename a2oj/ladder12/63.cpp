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

void addy(int* arr, int n, int y) {
    forsn(i,1,n) {
        arr[i] += y;
    }
}

int main() {
    fast_cin();
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    forsn(i,1,n+1)   cin >> arr[i];
    int t,v,x,y,q, curr_y=0;
    while(m--) {
        cin >> t;
        if(t==1) {
            cin >> v >> x;
            if(curr_y!=0) {
                addy(arr, n+1, curr_y);
                curr_y = 0;
            }
            arr[v] = x;
        }
        else if (t==2) {
            cin >> y;
            curr_y+=y;
        }
        else {
            cin >> q;
            if(curr_y!=0) {
                addy(arr, n+1, curr_y);
                curr_y = 0;
            }
            cout << arr[q] << ln;
        }
    }
    return 0;
}
