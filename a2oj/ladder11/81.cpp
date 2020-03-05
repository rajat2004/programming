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

#define N 1000001
bool hashset[N];

void gen_primes() {
    for (int p = 2; p * p < N; p++)
        if (hashset[p] == true)
            for (int i = p * 2; i < N; i += p)
                hashset[i] = false;
}

int count_divs(ll n) {
    int total = 1;
    for (int p = 2; p <= n; p++) {
        if (hashset[p]) {
            int count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}

int main() {
    fast_cin();
    memset(hashset, true, sizeof(hashset));
    gen_primes();

    int a,b,c;
    cin >> a >> b >> c;
    ll count = 0, mul;
    unordered_map<int,int> divs;
    unordered_map<int, int>:: iterator itr;

    forsn(i,1,a+1) {
        forsn(j,1,b+1) {
            forsn(k,1,c+1) {
                mul = i*j*k;
                itr = divs.find(mul);

                if(itr==divs.end()) {
                    int c_div = count_divs(mul);
                    divs[mul] = c_div;
                    count = (count + c_div)%1073741824;
                } else {
                    count = (count + itr->second)%1073741824;
                }

            }
        }
    }

    cout << count << ln;

    return 0;
}
