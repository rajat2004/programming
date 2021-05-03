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

uint32_t Not(uint32_t x) {
    uint32_t tmp = 1 << ((int)log2(x) + 1);
    // dbg(tmp);
    return tmp - 1 - x;
}

void solve() {
    string ss, se;
    cin >> ss >> se;
    uint32_t s = stoi(ss, nullptr, 2), e = stoi(se, nullptr, 2);


    unordered_set<uint32_t> visited;
    queue<uint32_t> q;
    int steps = 0;
    q.push(s);
    visited.insert(s);

    while(!q.empty()) {
        int N = q.size();
        while(N--) {
            auto curr = q.front();
            // dbg(curr);
            q.pop();

            if (curr==e) {
                cout << steps << endl;
                return;
            }

            auto n2 = Not(curr);
            // dbg(n2);
            if (!visited.count(n2)) {
                visited.insert(n2);
                q.push(n2);
            }

            auto n1 = curr << 1;
            if (n1<INT32_MAX && !visited.count(n1)) {
                q.push(n1);
                visited.insert(n1);
            }

        }

        steps++;
    }

    cout << "IMPOSSIBLE" << ln;
}

int main() {
    // fast_cin();

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    cin >> t;
    int id = 1;
    while(t--) {
        printf("Case #%d: ", id);
        solve();
        id++;
    }
    return 0;
}
