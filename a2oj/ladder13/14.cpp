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

void solve() {
    int row,col;
    cin >> row >> col;
    vector<v32> mat(row, v32(col,0));
    char ch;
    forn(i,row) {
        forn(j,col) {
            cin >> ch;
            if (ch=='S')    mat[i][j]=1;
        }
    }

    int curr = 0;

    while(true) {
        int old_curr = curr;

        for(int i=0; i<row; i++) {
            int count=0;
            bool pre = false;

            for(int j=0; j<col; j++) {
                if(mat[i][j]==1) {
                    pre = true;
                    break;
                }
                else if (mat[i][j]==0)  count++;
            }

            if(pre || count==0) continue;
            else {
                for(int j=0; j<col; j++) {
                    if (mat[i][j]==0)   mat[i][j]=-1;
                }
                curr += count;
                break;
            }
        }

        for (int j=0; j<col; j++) {
            int count=0;
            bool pre = false;

            for(int i=0; i<row; i++) {
                if(mat[i][j]==1) {
                    pre = true;
                    break;
                }
                else if (mat[i][j]==0)  count++;
            }

            if(pre || count==0) continue;
            else {
                for(int i=0; i<row; i++) {
                    if (mat[i][j]==0)   mat[i][j]=-1;
                }
                curr += count;
                break;
            }
        }

        if (old_curr==curr) break;
    }

    cout << curr << ln;
}

int main() {
    fast_cin();
    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
