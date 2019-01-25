#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

using namespace std;


int main() {
    int n, k, count = 0;
    cin >> n >> k;
    set<long> sett;
    repeat(i, n){
        int temp;
        cin >> temp;
        sett.insert(temp);
    }
    for(auto x:sett){
        long temp = x + k;
        if(sett.find(temp) != sett.end())
            ++count;
    }
    cout << count << endl;
    return 0;
}
