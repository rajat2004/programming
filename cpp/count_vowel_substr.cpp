// https://www.geeksforgeeks.org/count-substrings-that-contain-all-vowels-set-2/

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

vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    for(const auto &el : vowels) {
        if (el==c)
            return true;
    }
    return false;
}

bool allVowelsPresent(const unordered_map<char, int> &mp) {
    for(auto it=mp.begin(); it!=mp.end(); it++) {
        if (it->second <= 0)
            return false;
    }
    return true;
}

int countSubstr(const string &s) {
    unordered_map<char, int> mp;

    for(auto c:vowels)
        mp[c] = 0;

    int start=0, count=0, n=s.length();

    for(int i=0; i<n; i++) {
        mp[s[i]]++;

        while (allVowelsPresent(mp)) {
            count += n-i;
            mp[s[start]]--;
            start++;
        }
    }

    return count;
}

void solve() {
    string s;
    cin >> s;

    int count=0;
    string tmp;

    for(int i=0; i<s.length(); i++) {
        if (isVowel(s[i]))
            tmp += s[i];
        else {
            if (tmp.length() > 0)
                count += countSubstr(tmp);

            tmp = "";
        }
    }

    cout << count << ln;
}

int main() {
    fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
