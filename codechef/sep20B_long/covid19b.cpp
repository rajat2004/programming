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
    int n;
    cin >> n;
    v32 vel(n);
    input(vel, n);
    vv32 pos;
    v32 curr_pos;
    unordered_set<int> curr_same;
    vector<unordered_set<int>> same;
    forsn(i,1,n+1) {
        curr_pos.push_back(i);
    }

    // printarr(vel, n);
    // cout << ln;
    // printarr(curr_pos, n);
    // cout << ln;
    int it=0;

    while(true) {
        pos.push_back(curr_pos);
        same.push_back(curr_same);

        bool done=false;
        curr_same.clear();

        // dbg(it);
        forn(i,n) {
            curr_pos[i] += vel[i];
            // cout << curr_pos[i] << " ";
            if (curr_pos[i]>100)
                done = true;
        }
        // cout << ln;
        forn(i,n) {
            forn(j,i) {
                if (curr_pos[j]==curr_pos[i]) {
                    curr_same.insert(j);
                    curr_same.insert(i);
                }
            }
        }

        if (done)
            break;

        if (curr_pos == pos[pos.size()-1])
            break;

        it++;
    }

    int max_inf=INT_MIN, min_inf=INT_MAX;


    for(int inf=0; inf<n; inf++) {
        // if (vel[inf]==0) {
        //     max_inf = max(max_inf, 1);
        //     min_inf = min(min_inf, 1);
        //     continue;
        // }

        int c=same.size();
        unordered_set<int> curr_inf;
        curr_inf.insert(inf);

        for(int i=0; i<c; i++) {
            // bool done_for_this_pos = false;

            for (auto el:curr_inf) {
                if (same[i].find(el)!=same[i].end()) {
                    // done_for_this_pos = true;

                    for(auto new_ones : same[i])
                        curr_inf.insert(new_ones);

                    // break;
                }
            }

            if (curr_inf.size()==n)
                break;
        }

        max_inf = max(max_inf, (int)curr_inf.size());
        min_inf = min(min_inf, (int)curr_inf.size());

        // dbg(inf);
        // dbg(max_inf);
        // dbg(min_inf);
    }

    cout << min_inf << " " << max_inf << endl;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
