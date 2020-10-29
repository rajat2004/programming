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
#define yes() cout << "Yes" << ln
#define no() cout << "No" << ln

const int MAXN=1e5;
vector<bool> isprime(MAXN+1, true);

void generate() {
    isprime[1] = false;
    isprime[2] = true;

    for(int i=4; i<MAXN; i+=2)
        isprime[i] = false;
    cout << "Hello" << endl;

    for(int i=3; i<MAXN; i+=2) {
        if (isprime[i]) {
            cout << i << endl;
            for(long long p=i*i; p<=MAXN; p+=i)
                isprime[p] = false;
        }
    }
}

void output(vector<int> &v) {
    int n=v.size();
    for(int start=0; start<n; start++) {
        cout << v[start];
        for(int i=(start+1)%n; i!=start; i=(i+1)%n)
            cout << " " << v[i];
        cout << endl;
    }
}

void solve() {
    int n;
    cin >> n;

    if (isprime[n]) {
        vector<int> res(n, 1);
        output(res);
    }
    else {
        vector<int> res(n-1, 1);
        int i;
        for(i=1; i<MAXN; i++) {
            if (!isprime[i] && isprime[n-1+i])
                break;
        }

        res.push_back(i);
        output(res);
    }

}

int main() {
    fast_cin();
    int t=1;
    cin >> t;
    generate();
    // while(t--) {
    //     solve();
    // }
    return 0;
}
