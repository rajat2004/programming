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

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        string s, pat;
        cin >> s >> pat;
        int schars[26], patchars[26];
        memset(schars, 0, 26*sizeof(int));
        memset(patchars, 0, 26*sizeof(int));

        for (auto c:pat)
            patchars[c-'a']++;

        for (auto c:s)
            schars[c-'a']++;

        for (int i=0; i<26; i++)
            schars[i] -= patchars[i];

        int limit= pat[0]-'a';
        for (int i=1; i<pat.length(); i++) {
            if (pat[i] != pat[i-1]) {
                if (pat[i] > pat[i-1])
                    limit = pat[i-1]-'a';
                else
                    limit = pat[i-1]-'a'-1;

                break;
            }
        }
        string res="";

        for (int i=0; i<=limit; i++) {
            while(schars[i]>0) {
                res += (char)(i+'a');
                schars[i]--;
            }
        }

        res += pat;

        for(int i=limit+1; i<26; i++) {
            while(schars[i]>0) {
                res += (char)(i+'a');
                schars[i]--;
            }
        }

        cout << res << ln;
    }
    return 0;
}
