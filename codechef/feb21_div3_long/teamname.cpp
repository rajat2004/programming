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

void solve() {
    int n;
    cin >> n;

    vector<string> store(n);
    forn(i,n)
        cin >> store[i];

    unordered_map<string, vector<char>> mp;

    for(const auto &s : store) {
        mp[s.substr(1)].push_back(s[0]);
    }

    int res = 0;
    for (auto it1=mp.begin(); it1!=mp.end(); it1++) {
        for(auto it2=mp.begin(); it2!=mp.end(); it2++) {
            int x = set_intersection(it1->second.begin(), it1->second.end(),
                                    it2->second.begin(), it2->second.end());
        }
    }

    // unordered_set<string> funny(store.begin(), store.end());
    // int res = 0;

    // vector<int> freq_acc(26, 0), freq_av(26, 0);
    // for(auto &s : store) {
    //     char orig = s[0];
    //     freq_av[orig-'a']++;

    //     for(char c='a'; c<='z'; c++) {
    //         s[0] = c;

    //         if (funny.find(s)==funny.end()) {
    //             freq_acc[c-'a']++;
    //         }
    //     }

    //     s[0] = orig;
    //     // freq_av[s[0]-'a']++;
    // }

    // forn(i, 26) {
    //     res += min(freq_av[i], freq_acc[i]);
    // }

    // for(auto &s : store) {
    //     char orig = s[0];

    //     for(char c='a'; c<='z'; c++) {
    //         if (c!=orig && freq_av[c-'a']>0) {
    //             s[0] = c;
    //             if (funny.find(s) == funny.end())
    //                 res += freq_av[c-'a'];
    //         }
    //     }
    // }

    // forn(i,n) {
    //     for(int j=i+1; j<n; j++) {
    //         swap(store[i][0], store[j][0]);

    //         if (funny.find(store[i]) == funny.end()
    //             && funny.find(store[j]) == funny.end())
    //             res += 2;

    //         swap(store[i][0], store[j][0]);
    //     }
    // }

    cout << res << endl;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
