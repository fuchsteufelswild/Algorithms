#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

using namespace std;
int visited[11][11];
template<class T> void setMax(T &a, const T &b) { if(a < b) a = b; }

void trav(vector<pair<int, int> > vec[11][11], int n, int m, int i, int j, int *temp){
    if(visited[i][j])
        return;
    visited[i][j] = 1;
    for(auto y: vec[i][j]){
        if(!visited[y.first][y.second]){
            ++(*temp);
            trav(vec, n, m, y.first, y.second, temp);
        }
    }
}

int main() {
    int n, m, max = 0, flag = 0;
    cin >> n >> m;
    int val[11][11];
    int visited[11][11];
    vector<pair<int, int> > vec[11][11];
    repeat(i, n){
        repeat(j, m)
            cin >> val[i][j];
    }
    repeat(i, n){
        repeat(j, m){
            if(val[i][j] == 1){
                int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
            if(i != 0){
                if(val[i - 1][j] == 1) vec[i][j].push_back(pair<int, int>(i - 1, j));
                check1 = 1;
            }
            if(i != n - 1){
                if(val[i + 1][j] == 1) vec[i][j].push_back(pair<int, int>(i + 1, j));
                check2 = 1;
            }
            if(j != 0){
                if(val[i][j - 1] == 1) vec[i][j].push_back(pair<int, int>(i, j - 1));
                check3 = 1;
            }
            if(j != m - 1){
                if(val[i][j + 1] == 1) vec[i][j].push_back(pair<int, int>(i, j + 1));
                check4 = 1;
            }
                if(check1 && check3){
                    if(val[i - 1][j - 1] == 1) vec[i][j].push_back(pair<int, int>(i - 1, j - 1));
                }
                if(check1 && check4){
                    if(val[i - 1][j + 1] == 1) vec[i][j].push_back(pair<int, int>(i - 1, j + 1));
                }
                if(check2 && check3){
                    if(val[i + 1][j - 1] == 1) vec[i][j].push_back(pair<int, int>(i + 1, j - 1));
                }
                if(check3 && check4){
                    if(val[i + 1][j + 1] == 1) vec[i][j].push_back(pair<int, int>(i + 1, j + 1));
                }
            }
            flag = 1;
        }
    }
    repeat(i, n){
        repeat(j, m){
            if(vec[i][j].size()){
                int *temp = new int(1);
                trav(vec, n, m, i, j, temp);
                setMax(max, *temp);
            }
        }
    }
    if(flag){
        setMax(max, 1);
    }
    cout << max << endl;
    return 0;
}
