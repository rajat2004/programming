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

void generate(int id, const vector<int>& all_cards, lluu sum, lluu prod, lluu max_sum, lluu &max_score) {
    if (id == all_cards.size()) {
        if (sum == prod)
            max_score = max(max_score, sum);

        return;
    }

    generate(id+1, all_cards, sum+all_cards[id], prod, max_sum, max_score);

    if (prod*all_cards[id] < max_sum)
        generate(id+1, all_cards, sum, prod*all_cards[id], max_sum, max_score);

}

void solve(int id) {
    int m;
    cin >> m;
    vp32 cards(m);
    int tot_n = 0;
    forn(i, m) {
        cin >> cards[i].first >> cards[i].second;
        tot_n += cards[i].second;
    }

    vector<int> all_cards;
    for(auto p : cards) {
        forn(i, p.second)
            all_cards.push_back(p.first);
    }

    sort(all_cards.begin(), all_cards.end());
    lluu max_sum = accumulate(all_cards.begin(), all_cards.end(), 0);

    lluu max_score = 0;
    lluu prod = 1, sum = 0;

    generate(0, all_cards, sum, prod, max_sum, max_score);
    printf("Case #%d: %llu\n", id, max_score);
}

int main() {
    fast_cin();

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    cin >> t;
    int id = 1;
    while(t--) {
        solve(id);
        id++;
    }
    return 0;
}
