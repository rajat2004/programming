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

void err() {
    cout << -1 << endl;
}

int main() {
    fast_cin();
    int n,a,c[8]={0,0,0,0,0,0,0,0};
    cin >> n;
    forn(i,n) {
        cin >> a;
        c[a]++;
    }

    if(c[5]!=0 || c[7]!=0) {
        err();
        return 0;
    }

    string s;

    if(c[4]!=0) {
        if(c[4]>c[2] || c[4]>c[1]) {
            err();
            return 0;
        }
        while(c[4]--) {
            s+="1 2 4\n";
            c[2]--;
            c[1]--;
        }
        c[4]+=1;
    }

    if (c[2]!=0) {
        if(c[2]>c[1] || c[2]>c[6]) {
            err();
            return 0;
        }
        while(c[2]--) {
            s+="1 2 6\n";
            c[1]--;
            c[6]--;
        }
        c[2]+=1;
    }

    if (c[3]!=0) {
        if(c[3]!=c[1] || c[3]!=c[6]) {
            err();
            return 0;
        }
        while(c[3]--) {
            s+="1 3 6\n";
            c[1]--;
            c[6]--;
        }
        c[3]+=1;
    }

    for(int i=1; i<=7; i++) {
        if(c[i]!=0) {
            // printf("%d %d",i,c[i]);
            err();
            return 0;
        }
    }
    cout << s;


    return 0;
}
