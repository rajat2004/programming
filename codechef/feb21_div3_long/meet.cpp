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

v32 convert(const std::string &s) {
    int id = 0;
    if (s[0]==' ')
        id++;

    int hrs=0, mins=0;
    hrs = stoi(s.substr(id, 2));
    id+=3;
    mins = stoi(s.substr(id, 2));
    id+=3;

    if (s[id]=='A' && hrs==12)
        hrs = 0;

    if (s[id]=='P' && hrs!=12)
        hrs += 12;

    return {hrs, mins};
}

void solve() {
    string p;
    getline(cin, p);
    auto mt = convert(p);

    int n;
    cin >> n;   cin>>ws;
    string res = "";

    forn(i,n) {
        string s, tmp;
        getline(cin, s);
        vector<string> v;
        stringstream ss(s);

        while(getline(ss, tmp, 'M')) {
            v.push_back(tmp);
        }

        auto l = convert(v[0]), r = convert(v[1]);

        if (r[0]<l[0] || (r[0]==l[0] && r[1]<l[1]))
            r[0] += 24;

        auto lesser = [](const v32& t1, const v32& t2) {
            return (t1[0] < t2[0]) || (t1[0]==t2[0] && t1[1]<=t2[1]);
        };

        if (lesser(l, mt) && lesser(mt, r))
            res += "1";
        else
            res += "0";
    }

    cout << res << endl;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t; cin >> ws;
    while(t--) {
        solve();
    }
    return 0;
}
