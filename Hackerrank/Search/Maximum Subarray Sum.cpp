#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

typedef long long ll;
using namespace std;

template<class T> void setMax(T &a, const T &b) { if(a < b) a = b; }

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n, m, max = 0;
        cin >> n >> m;
        ll pre[n];
        set<ll> sett;
        repeat(i, n){
            ll temp;
            cin >> temp;
            if(!i)
                pre[0] = temp % m;
            else
                pre[i] = (pre[i - 1] + temp) % m;
            setMax(max, pre[i]);
        }
        repeat(i, n){
            set<ll>::iterator itr = sett.lower_bound(pre[i] + 1);
            if(itr != sett.end())
                setMax(max, pre[i] - *itr + m);
            sett.insert(pre[i]);
        }
        cout << max << endl;
    }
    return 0;
}
