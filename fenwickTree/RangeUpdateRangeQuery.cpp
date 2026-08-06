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
        vector<int>bit1,bit2;;
        int n;

        fenwickTree(int n){
            this->n = n+1;
            bit1.assign(n+1,0);
            bit2.assign(n+1,0);
        }


        void update(int idx,int val,vector<int>&bit){
            for(idx; idx < n ; idx+=(idx&-idx)){
                bit[idx]+=val;
            }
        }

        int query(int idx,vector<int>&bit){
            int sum=0;
            for(idx;idx>0 ; idx-=(idx&-idx)){
                sum+=bit[idx];
            }

            return sum;
        }


        void rangeUpdate(int l,int r, int val){
            update(l,val,bit1);
            update(r+1,-val,bit1);

            update(l,(l-1)*val,bit2);
            update(r+1,-val*r,bit2);
        }

        int prefixQuery(int idx){
            return query(idx,bit1)*idx - query(idx,bit2);
        }

        int rangeQuery(int l, int r){
            return prefixQuery(r) - prefixQuery(l-1);
        }


        

};

int main(){

}