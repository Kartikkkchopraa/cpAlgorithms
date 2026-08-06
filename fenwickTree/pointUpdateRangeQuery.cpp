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


class fenwickTree{
    public:
        vector<int>bits;
        int n;

        fenwickTree(int n){
            this->n = n+1;
            bits.assign(n+1,0);
        }


        void update(int idx,int val){
            for(idx ; idx < n ; idx+=(idx&-idx)){
                bits[idx] += val;
            }
        }


        int query(int idx){
            int sum = 0;
            for(idx ; idx > 0 ; idx-=(idx&-idx)){
                sum += bits[idx];
            }

            return sum;
        }

        int rangeQuery(int l, int r){
            return query(r) - query(l-1);
        }

};

int main(){

}