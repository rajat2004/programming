#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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

int main() {
    fast_cin();
    int n,a;
    cin >> n;
    int beg, end, last;
    int arr[n];
    bool is_1_segment = false, segment_started = false;
    cin >> last;
    arr[0] = last;
    for(int i=1; i<n; i++) {
        cin >> a;
        arr[i] = a;
        if(last > a) {
            if (is_1_segment) {
                // Another segment
                cout << "no" << ln;
                return 0;
            }
            // Segment started
            if(!segment_started) {
                segment_started = true;
                beg = i-1;
            }
        }
        else {
            if (segment_started) {
                // Segment ends
                end = i-1;
                segment_started = false;
                is_1_segment = true;
            }
        }
        last = a;
    }
    if(segment_started) {
        end = n-1;
        is_1_segment = true;
    }
    if(!is_1_segment) {
        cout << "yes\n1 1\n";
        return 0;
    }

    if(beg!=0 && arr[end] < arr[beg-1]) {
        cout << "no" << ln;
        return 0;
    }

    if(end!=(n-1) && arr[beg] > arr[end+1]) {
        cout << "no" << ln;
        return 0;
    }

    cout << "yes" << ln;
    cout << beg+1 << " " << end+1 << ln;
    return 0;
}
