#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(i, j) (i < j ? i : j)
#define MAX(i, j) (i > j ? i : j)
using namespace std;

template<class T> void setMax(T &a, const T &b){ if(a < b) a = b; }


int findMin(int x, int y, int z, int t){
    int min1 = MIN(x, y);
    int min2 = MIN(z, t);
    return MIN(min1, min2);
}

int findCross(char grid[15][15], int pos1, int pos2, char used[15][15], int row, int col, int flag, int a){
    if(pos1 == 0 || pos1 == row || pos2 == 0 || pos2 == col){
        int max = 1;
        if(flag == 1){
            return 1;
        }
        used[pos1][pos2] = '~';
        repeat(j, row){
            repeat(k, col){
                int temp = findCross(grid, j, k, used, row, col, 1, 1);
                setMax(max, temp);
            }
        }
        return max;
    }
    int up, down, right, left, count, area;
    down = row - pos1;
    up = row - down + 1;
    right = col - pos2;
    left = col - right + 1;
    count = findMin(down, up, right, left);
    int te = 1;
    for(int i = 1; i < count; ++i){
        if(grid[pos1 + i][pos2] == 'B' || 
               grid[pos1 - i][pos2] == 'B' || 
               grid[pos1][pos2 + i] == 'B' || 
               grid[pos1][pos2 - i] == 'B'){
               break;
        }
        te = i + 1;
    }
    count = te;
    int max = 1;
    if(flag == 1){
        int t = 0;
        for(int i = 1; i < count; ++i){
            if(used[pos1 + i][pos2] == '~' || 
               used[pos1 - i][pos2] == '~' || 
               used[pos1][pos2 + i] == '~' || 
               used[pos1][pos2 - i] == '~'){
                break;
            }
            t = i;
        }
        
        int temp = 4 * t + 1;
        return temp * a;
    }
    used[pos1][pos2] = '~';
    for(int i = 0; i < count; ++i){
        if(i == 0){
            area = 4 * i + 1;
            repeat(j, row){
            repeat(k, col){
                int temp = findCross(grid, j, k, used, row, col, 1, area);
                setMax(max, temp);
            }
        }
            continue;
        }
        used[pos1 + i][pos2] = '~';
        used[pos1 - i][pos2] = '~';
        used[pos1][pos2 + i] = '~';
        used[pos1][pos2 - i] = '~';
        area = (4 * i) + 1;
        repeat(j, row){
            repeat(k, col){
                int temp = findCross(grid, j, k, used, row, col, 1, area);
                setMax(max, temp);
            }
        }
    }
    return max;
    
}

int main() {
    short n, m;
    cin >> n >> m;
    char grid[15][15];
    repeat(i, n){
        repeat(j, m){
            cin >> grid[i][j];
        }
    }
    int max = 0;
    repeat(i, n){
        repeat(j, m){
            char used[15][15];
            repeat(k, n){
                repeat(l, m){
                    used[k][l] = '0';
                }
            }
            if(grid[i][j] == 'G'){
                int temp = findCross(grid, i, j, used, n, m, 0, 0);
                setMax(max, temp);
            }
        }
    }
    cout << max << endl;
    return 0;
}
