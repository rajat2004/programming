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
    int n,k;
    cin >> n >> k;
    v32 ocards(n);
    input(ocards, n);
    set<int> set_cards(ocards.begin(), ocards.end());
    v32 cards(set_cards.begin(), set_cards.end());

    priority_queue<int> pq_gaps;
    int max_gap_bw = 0;
    forn(i, cards.size()-1) {
        int gap = cards[i+1] - cards[i] - 1;
        max_gap_bw = max(max_gap_bw, gap);
        pq_gaps.push((gap+1)/2);
    }

    pq_gaps.push(cards.front() - 1);
    pq_gaps.push(k - cards.back());


    int maxgap1=0, maxgap2=0;

    maxgap1 = pq_gaps.top();
    pq_gaps.pop();

    maxgap2 = pq_gaps.top();
    pq_gaps.pop();

    int ans = max(maxgap1+maxgap2, max_gap_bw);
    cout << (double)ans/k << endl;
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
