#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <map>
#define rep(i, m, n) for(int i = m; i < n; ++i)
#define repb(i, m, n) for(int i = m; i > n; --i)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define sc second
#define di deque<int>
#define mii map<int, int>
#define si set<int>
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

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k, acc;
        ll b;
        int flag = 0;
        cin >> n >> k;
        cin >> b;
        if(b == 1){
            if(k >= n){
                cout << n << endl;
                continue;
            }
        }
        ll t = (1ll * (k + k - b) / 2);
        int cnt = 0, cnt1 = 0, cnt2 = 0;
        while(t){
            t /= 10;
            ++cnt;
        }
        t = b;
        while(t){
            t /= 10;
            ++cnt1;
        }
        t = n;
        while(t){
            t /= 10;
            ++cnt2;
        }
        if(1ll * b * (b + 1) / 2 > n || 1ll * n / b >= k || cnt + cnt1 < cnt2){
            cout << - 1 << endl;
            continue; 
        }
        acc = 0;
        ll u = MIN(1ll * k, 1ll * ((ll)n - (1ll * b * (b - 1) / 2)));
        ll l = 1;
        set<ll> st;
        vector<ll> low;
        vector<ll> up;
        low.pb(0);
        up.pb(u + 1);
        ll ub = u;
        rep(i, 0, b - 1){
            st.insert(l);
            acc += l;
            low.pb(l++);
        }
        rep(i, 0, b){
            set<ll>::iterator itr;
            if(st.find(1ll * ((ll)n - (ll)acc)) == st.end() && 1ll * (n - acc) >= 1 && 1ll * (n - acc) <= (ll)ub){
                for(auto x:low){
                    if(x)
                        cout << x << " ";
                }
                for(auto x:up){
                    if(x <= ub)
                        cout << x << " ";
                }
                cout << n - acc << endl;
                flag = 1;
                break;
            }
            else if(acc < n){
                if(low.back() == 0)
                    break;
                itr = st.find(low.back());
                st.erase(itr);
                acc -= low.back();
                low.pp();
                acc += up.back() - 1;
                st.insert(up.back() - 1);
                up.pb(up.back() - 1);
            }
        }
        if(flag)
            continue;
        cout <<  - 1 << endl;
    }
    return 0;
}
