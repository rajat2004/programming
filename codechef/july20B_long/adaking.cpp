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

int matrix[8][8];

void print_matrix() {
    forn(i,8) {
        forn(j,8) {
            switch (matrix[i][j])
            {
            // Empty
            case 0:
                cout << ".";
                break;

            // Obstacle
            case 1:
                cout << "X";
                break;

            // King
            case 2:
                cout << "O";
                break;

            default:
                break;
            }
        }
        cout << ln;
    }
}

void init_matrix() {
    // Init each cell to obstacle
    forn(i,8) {
        forn(j,8) {
            matrix[i][j]=1;
        }
    }

    // Place King in top-left
    matrix[0][0] = 2;
}

void fun(int k) {
    if(k==1)    return;
    int off = 1;

    while(k>1) {
        for(int i=0; i<=off; i++) {
            if(k==1)    return;
            matrix[off][i] = 0;
            k--;
        }

        for(int i=0; i<off; i++) {
            if(k==1) return;
            matrix[i][off] = 0;
            k--;
        }

        off+=1;
    }
}

int main() {
    fast_cin();

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        init_matrix();
        fun(k);
        print_matrix();
        cout << ln;
    }
    return 0;
}
