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
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int k;
        cin >> k;
        // int arr[k], greater_c=0, lesser_c=0;
        int arr[k], count=0, greater_c=0, lesser_c=0, c=0;
        forn(i,k)   cin >> arr[i];

        for(int i=1;i<k; i++) {
            if(arr[i]>arr[i-1]) {
                greater_c++;
                count++;
            }
            else if(arr[i]<arr[i-1]) {
                lesser_c++;
                count--;
            }

            if(abs(count)>=4) {
                c++;
                count = 0;
                if(greater_c>=4) {
                    greater_c=0;
                }
                if(lesser_c>=4) {
                    lesser_c=0;
                }
            }

        }

        // int c = (greater_c/4) + (lesser_c/4);
        // int c = abs(count)/4 + abs(greater_c)/4 + abs(lesser_c)/4;
        // if(abs(count)==abs(greater_c))
        //     c-=abs(greater_c)/4;
        // if(abs(count)==abs(lesser_c))
        //     c-=abs(greater_c)/4;

        printf("Case #%d: %d\n", t, c);
    }
    return 0;
}
