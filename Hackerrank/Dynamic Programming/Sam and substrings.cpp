#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < n; ++i)
#define repb(i, m, n) for(int i = m; i > n; --i)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define first fi
#define second sc
#define mii map<int, int>
#define sz(x) ((int) (x).size())
#define vi vector<int>

template<class T, class U> void setMax(T &a, const U &b) { if(a < b) a = b; }
template<class T, class U> void setMin(T &a, const U &b) { if(a > b) a = b; }
typedef long long ll;
typedef long double ld;
const int inf = (int)1e9 + (int)1e5;
const ll infl = (ll)1e18 + (ll)1e10; 
const int MAXN = 100001;
const int mod = 1000000007;
using namespace std;

string s;
ll acc[2 * MAXN - 1];
ll res;

int main(){
    cin >> s;
    acc[0] = (int)s[0] - 48;
    res += acc[0];
    rep(i, 1, s.size())
        (res += ((acc[i] = (i + 1) * ((int)s[i] - 48) + acc[i - 1] * 10) %= mod)) %= mod;
    cout << res << endl;
}
