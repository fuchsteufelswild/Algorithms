#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)
#define repeat(i, n) for(int i = 0; i < n; ++i)
using namespace std;

template <class T> void setMax(T &a, const T &b){ if (a < b) a = b; }

template <class T> void setMin(T &a, const T &b){ if(a > b) a = b; }

int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
    int maxrl = cQueen - 1;
    int maxrr = n - cQueen;
    int maxcu = rQueen - 1;
    int maxcd = n - rQueen;
    int maxrne = MIN(n - cQueen, rQueen - 1);
    int maxrsw = MIN(cQueen - 1, n - rQueen);
    int maxrnw = MIN(rQueen - 1, cQueen - 1);
    int maxrse = MIN(n - rQueen, n - cQueen);
    repeat(i, k){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        if(rObstacle == rQueen){
            if(cObstacle < cQueen){
                setMin(maxrl, cQueen - 1 - cObstacle);
            }
            else if(cObstacle > cQueen){
                setMin(maxrr, cObstacle - cQueen - 1);
            }
        }
        else if(cObstacle == cQueen){
            if(rObstacle < rQueen){
                setMin(maxcu, rQueen - rObstacle - 1);
            }
            else if(rObstacle > rQueen){
                setMin(maxcd, rObstacle - rQueen - 1);
            }
        }
        else if(cObstacle > cQueen){
            if(cObstacle - cQueen != abs(rQueen - rObstacle)){
                continue;
            }
            if(rObstacle < rQueen){
                setMin(maxrne, MIN(n - cQueen, rQueen - 1) - MIN(n - cObstacle, rObstacle - 1) - 1);
            }
            else if(rObstacle > rQueen){
                setMin(maxrse, MIN(n - rQueen, n - cQueen) - MIN(n - rObstacle, n - cObstacle) - 1);
            }
        }
        else if(cObstacle < cQueen){
            if(abs(cObstacle - cQueen) != abs(rQueen - rObstacle)){
                continue;
            }
            if(rObstacle < rQueen){
                setMin(maxrnw, MIN(rQueen - 1, cQueen - 1) - MIN(rObstacle - 1, cObstacle - 1) -  1);
            }
            else if(rObstacle > rQueen){
                setMin(maxrsw, MIN(cQueen - 1, n - rQueen) - MIN(cObstacle - 1, n - rObstacle) - 1);
            }
        }
    }
    long int result = maxrne + maxrse + maxrsw + maxrnw + maxcd + maxcu + maxrr + maxrl;
    cout << result << endl;
    return 0;
}
