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

bool is_even(ll n) {
    return (n%2)==0;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int,int> amap,bmap;
        int x, min_el=INT_MAX;
        forn(i,n) {
            cin >> x;
            amap[x]++;
            min_el = min(x, min_el);
        }

        forn(i,n) {
            cin >> x;
            bmap[x]++;
            min_el = min(x, min_el);
        }

        v64 ainsert, binsert;
        bool flag = false;

        for(auto itr=amap.begin(); itr!=amap.end(); itr++) {
            int acount = itr->second;
            auto bitr = bmap.find(itr->first);
            ll tot_count = acount;

            if (bitr!=bmap.end()) {
                tot_count += bitr->second;
            }

            if(!is_even(tot_count)) {
                flag = true;
                break;
            }

            // To be inserted in A
            if (acount < (tot_count/2)) {
                for(int i=0; i<(tot_count/2 - acount); i++) ainsert.pb(itr->first);
            }
            // To be inserted in B
            else {
                for(int i=0; i<(acount - tot_count/2); i++) binsert.pb(itr->first);
            }

            bmap.erase(itr->first);
        }

        for(auto itr=bmap.begin(); itr!=bmap.end(); itr++) {
            if(!is_even(itr->second)) {
                flag = true;
                break;
            }

            // To be inserted in A
            for(int i=0; i<(itr->second/2); i++)    ainsert.pb(itr->first);
        }


        if(flag) {
            cout << "-1" << ln;
        }
        else {
            ll sum = 0;
            sort(ainsert.begin(), ainsert.end());
            sort(binsert.begin(), binsert.end(), greater<int>());

            forn(i, ainsert.size()) {
                int tmp = min(ainsert[i], binsert[i]);
                sum +=  min(tmp, 2*min_el);
            }

            cout << sum << ln;
        }
    }
    return 0;
}
