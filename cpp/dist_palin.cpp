// https://www.codechef.com/problems/ENCD12

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

bool checkPalindrome(string &s) {
    v32 freq(26, 0);
    for(auto c:s)
        freq[c-'a']++;

    int oddc=0;
    forn(i,26) {
        if (freq[i]%2!=0)
            oddc++;
    }

    return oddc<=1;
}

void solve(string &s) {
    bool possible = checkPalindrome(s);
    if (!possible) {
        cout << "Impossible" << endl;
        return;
    }

    int count=0, n=s.length();
    for(int l=0; l<n/2; l++) {
        int r = n-l-1, j;

        for(j=r; j>=l; j--) {
            if (s[j]==s[l])
                break;
        }

        for(; j<r; j++) {
            swap(s[j], s[j+1]);
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t=1;
    // cin >> t;
    while(true) {
        string s;
        cin >> s;
        if (s[0]=='0')
            break;
        solve(s);
    }
    return 0;
}
