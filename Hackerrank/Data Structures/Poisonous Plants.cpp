#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#define repeat(i, n) for(int i = 0; i < n; ++i)
using namespace std;

template <class T> bool setMax(T & a, T const & b){ if(a <= b) {a = b; return true;} else{ return false; } }

template <class T> void setMin(T & a, T const & b){ if(a >= b) a = b;}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    repeat(i, n)
        cin >> arr[i];
    
    int *memo = new int[n]();
    int min = arr[0];
    int max = 0;
    vector<int> pos;
    pos.push_back(0);
    for(int i = 1; i < n; ++i){
        if(arr[i] > arr[i-1]){
            memo[i] = 1;
        }
        setMin(min, arr[i]);
        while(!pos.empty() && arr[pos.back()] >= arr[i]){
            if(arr[i] > min){
                setMax(memo[i], memo[pos.back()] + 1);
            }
            pos.pop_back();
        }  
        setMax(max, memo[i]);
        pos.push_back(i);
    }
    cout<<max<<endl;
}
