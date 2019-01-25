#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define repeat(i, n) for(int i = 0; i < n; ++i)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)
using namespace std;

template<class T> void setMax(T &a, const T &b) { if(a < b) a = b; }

template<class T> void setMin(T &a, const T &b) { if(a > b) a = b; }

int main() {
    int n, m, l;
    unsigned long long ans;
    cin >> n >> m >> l;
    ans = (long long)n * (long long)m;
    map<int, map<int, int> > mapp;
    repeat(u, l){
        int i, j, k;
        cin >> i >> j >> k;
        if(mapp.find(i) == mapp.end()){
            map<int, int> temp;
            temp.insert(pair<int, int>(MIN(j, k), MAX(j, k)));
            mapp[i] = temp;
        }
        else{
            int min = MIN(j, k), max = MAX(j, k);
            map<int, int>::iterator itr = mapp[i].upper_bound(min);
            if(itr == mapp[i].begin()){
                if(max >= itr -> first){
                    int ket = itr -> second;
                    mapp[i].erase(itr);
                    mapp[i].insert(pair<int, int>(min, MAX(max, ket)));
                }
                else
                    mapp[i].insert(pair<int, int>(min, max));
            }
            else{
                --itr;
                if(min == itr -> first)
                    mapp[i][itr -> first] = MAX(max, itr -> second);
                else if(min <= itr -> second){
                    if(max > itr -> second){
                        map<int, int>::iterator it = mapp[i].upper_bound(max);
                        --it;
                        if(it -> first == itr -> first)
                            mapp[i][itr -> first] = max;
                        else{
                            if(max >= it -> second){
                                map<int, int>::iterator x;
                                int val = itr -> first;
                                for(x = itr; x != it;){
                                    map<int, int>::iterator y = x;
                                    ++x;
                                    mapp[i].erase(y);
                                }
                                mapp[i].erase(x);
                                mapp[i][val] = max;
                            }
                        }
                        
                    }
                }
                else{
                    ++itr;
                    if(itr != mapp[i].end()){
                        if(max >= itr -> first){
                            map<int, int>::iterator it = mapp[i].upper_bound(max);
                            --it;
                            if(it != mapp[i].end()){
                                if(it -> second < max){
                                    map<int, int>::iterator x;
                                    for(x = itr; x != it;){
                                        map<int, int>::iterator y = x;
                                        ++x;
                                        mapp[i].erase(y);
                                    }
                                    mapp[i].erase(x);
                                    mapp[i].insert(pair<int, int>(min, max));
                                }
                            }
                            else{
                                int ket = itr -> second;
                                mapp[i].erase(itr);
                                mapp[i].insert(pair<int, int>(min, MAX(max, ket)));
                            }
                        }
                        else
                            mapp[i].insert(pair<int, int>(min, max));
                    }
                    else{
                        --itr;
                        if(min > itr -> second)
                            mapp[i].insert(pair<int, int>(min, max));
                        else if(min == itr -> second)
                            mapp[i].insert(pair<int, int>(itr -> second + 1, max));
                        else
                            mapp[i][itr -> first] = MAX(itr -> second, max);
                    }
                }
            }
        }
    }
    unsigned long long diff = 0;
    for(auto x:mapp){
        for(auto y:x.second)
            diff += (long long)y.second - (long long)y.first + 1;
    }
    cout << ans - diff << endl;
    return 0;
}
