#include <vector>           
#include <vector>           
#include <vector>           
#include <array>             
#include <iostream>         
#include <string>         
#include <cstring>          
#include <algorithm>        
#include <numeric>          
#include <cmath>            
#include <climits>          
#include <limits>           
#include <queue>            
#include <stack>            
#include <deque>            
#include <set>             
#include <map>              
#include <unordered_set>   
#include <unordered_map>    
#include <bitset>           
#include <functional>       
#include <iomanip>          
#include <sstream>          
#include <fstream>          
#include <cassert>          
#include <tuple>            
#include <utility>          
#include <list>             
#include <iterator>         
#include <random>           
#include <chrono>           
#include <cctype>           
#include <cstdio>           
#include <cstdlib> 

using namespace std;

class FenwickTree2D {
public:
    int n, m;
    vector<vector<long long>> bit;

    FenwickTree2D(int n, int m) {
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(n + 1, vector<long long>(m + 1, 0));
    }

    
    void update(int x, int y, long long val) {
        for (int i = x; i < n; i += (i & -i)) {
            for (int j = y; j < m; j += (j & -j)) {
                bit[i][j] += val;
            }
        }
    }

    
    long long query(int x, int y) {
        long long sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    
    long long rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2)
             - query(x1 - 1, y2)
             - query(x2, y1 - 1)
             + query(x1 - 1, y1 - 1);
    }
};