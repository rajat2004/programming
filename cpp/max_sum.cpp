// https://www.geeksforgeeks.org/sum-of-maximum-elements-of-all-possible-sub-arrays-of-an-array/

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

int findMaxSum(v32 &v, int n) {
    v32 grRight(n, n), grLeft(n, -1);
    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && v[st.top()]<v[i]) {
            grRight[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && v[st.top()]<v[i]) {
            grLeft[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int sum=0;
    for(int i=0; i<n; i++) {
        sum += v[i]*(grRight[i]-i)*(i-grLeft[i]);
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    v32 v(n);
    input(v,n);

    cout << findMaxSum(v, n) << endl;
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
