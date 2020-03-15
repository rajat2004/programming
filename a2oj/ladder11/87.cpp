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
    int n,a,b,c,na,nb,nc;
    cin >> n >> a >> b >> c;
    if(a==1 || b==1 || c==1) {
        cout << n << ln;
        return 0;
    }
    na = n/a;
    nb = n/b;
    nc = n/c;
    int sum=0, sum_i=0, sum_j=0, count=0;
    for(int i=0; i<=na; i++) {
        sum_i = i*a;
        if(sum_i > n)
            break;
        for(int j=0; j<=nb; j++) {
            sum_j = sum_i + j*b;
            if (sum_j > n)
                break;
            for(int k=0; k<=nc; k++) {
                sum = sum_j + k*c;
                if(sum > n)
                    break;
                if(sum == n)
                    count = max(count, i+j+k);
            }
        }
    }
    cout << count << endl;
    return 0;
}
