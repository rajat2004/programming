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

struct activity {
    p32 time;
    int idx;
    string p;

    activity(int s, int e, int id) {
        time.first = s;
        time.second = e;
        idx = id;
        p = "-1";
    }
};

bool comp1(activity a, activity b) {
    return a.time.first < b.time.first;
}

bool comp2(activity a, activity b) {
    return a.idx < b.idx;
}

int main() {
    fast_cin();
    int T;
    cin >> T;
    forn(t,T) {
        int n,s,e;
        cin >> n;
        vector<activity> v;
        forn(i,n) {
            cin >> s >> e;
            v.pb(activity(s,e,i));
        }

        sort(v.begin(), v.end(), comp1);

        bool c_free=true, j_free=true;
        int c_end = -1, j_end = -1;
        bool flag = false;
        string res = "";

        forn(i,n) {
            if (v[i].time.first >= c_end) c_free = true;

            if (v[i].time.first >= j_end) j_free = true;

            if(c_free) {
                v[i].p = "C";
                c_end = v[i].time.second;
                c_free = false;
            }
            else if (j_free) {
                v[i].p = "J";
                j_end = v[i].time.second;
                j_free = false;
            }
            else {
                flag = true;
                break;
            }
        }

        if(flag) {
            res = "IMPOSSIBLE";
        }
        else {
            sort(v.begin(), v.end(), comp2);
            forn(i,n) { res += v[i].p; }
        }
        printf("Case #%lli: %s\n", t+1, res.c_str());
    }
    return 0;
}
