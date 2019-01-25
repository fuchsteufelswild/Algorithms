#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#define repeat(i, n) for(int i = 0; i < n; ++i)
using namespace std;


template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }



int main() {
    int n;
    long int result = 0;
    cin >> n;
    vector<long int> arr(n);
    repeat(i, n){
        cin >> arr[i];
    }
    stack<long int> height;
    stack<int> pos;
    int temp;
    repeat(i, n){
        int last;
        if(height.size() == 0){
            height.push(arr[i]);
            pos.push(i);
        }
        else if(height.top() < arr[i]){
            height.push(arr[i]);
            pos.push(i);
        }
        else if(height.top() > arr[i]){
            while(height.size() > 0 && height.top() > arr[i]){
            setmax(result, (height.top() * (i - pos.top())));
            height.pop();
            if(pos.size() > 1){
                last = pos.top();
                pos.pop();
            }
            }
            if(height.size() != 0){
                pos.push(last);
            }
            height.push(arr[i]);
        }
    }
    temp = n;
    while(height.size() != 0){
        setmax(result, (height.top() * (temp - pos.top())));
        height.pop();
        pos.pop();
    }
    cout << result << endl;
    return 0;
}
