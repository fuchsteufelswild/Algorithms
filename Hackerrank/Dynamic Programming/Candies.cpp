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

mii mapp;
int n;

int main(){
	cin >> n;
	vector<int> arr(n);
	int c[n];
	rep(i, 0, n)
		cin >> arr[i];
	rep(i, 0, n){
		if(!i){
			if(arr[i] > arr[i + 1])
				mapp[i] = 3;
			else if(arr[i] <= arr[i + 1])
				mapp[i] = 1;
		}
		if(i == n - 1){
			if(arr[i] > arr[i - 1])
				mapp[i] = 2;
			else if(arr[i] <= arr[i - 1])
				mapp[i] = 1;
		}
		if(arr[i] <= arr[i - 1] && arr[i] <= arr[i + 1])
			mapp[i] = 1;
		else if(arr[i] > arr[i - 1] && arr[i] <= arr[i + 1])
			mapp[i] = 2;
		else if(arr[i] <= arr[i - 1] && arr[i] > arr[i + 1])
			mapp[i] = 3;
		else if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			mapp[i] = 4;
	}
	rep(i, 0, n){
		if(mapp[i] == 1)
			c[i] = 1;
	}
	rep(i, 0, n){
		if(mapp[i] == 2)
			c[i] = c[i - 1] + 1;
	}
	repb(i, n - 1, -1){
		if(mapp[i] == 3)
			c[i] = c[i + 1] + 1;
	}
	rep(i, 0, n){
		if(mapp[i] == 4)
			c[i] = MAX(c[i - 1], c[i + 1]) + 1;
	}
	ll res = 0;
	rep(i, 0, n)
		res += c[i];
	cout << res << endl;
	return 0;
}
