#include <bits/stdc++.h>
#define MIN(x, y) (x > y ? x : y)
using namespace std;

template<class T> void setMin(T &a, const T &b){ if (a > b) a = b; }


template<class T> void setMax(T &a, const T &b){ if (a < b) a = b; }

int main() {
    int memo[1000001];
    for(int i = 0; i < 1000001; ++i){
        memo[i] = 0;
    }
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 3;
    for(int i = 1; i < 1000001; ++i){
        if(memo[i] == 0 || memo[i] > (memo[i - 1] + 1)){
             memo[i] = memo[i - 1] + 1;
        }
        for(int j = 1; j <= i && j * i < 1000001; ++j){
            if(memo[i * j] == 0 || memo[i * j] > (memo[i] + 1)){
                memo[i * j] = memo[i] + 1;
            }
        }
    }
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int N;
        cin >> N;
        cout << memo[N] << endl;
    }
    return 0;
}
