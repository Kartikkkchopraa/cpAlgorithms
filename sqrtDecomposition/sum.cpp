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

class sqrtDecomposition{
    public:
        int n;
        int len;
        
        vector<long long>arr;
        vector<long long>blocks;
        
        sqrtDecomposition(vector<long long>&a){
            n = a.size();
            len = sqrt(n+.0)+1;
            
            blocks.assign(len,0);
            arr = a;
            
            
            for(int i=0 ; i<n ; i++){
                blocks[i/len] += a[i];
            }
        }
        
        
        void update(int idx , long long val){
            blocks[idx / len ] += (val - arr[idx]);
            arr[idx] = val;
        }
        
        
        long long rangeSum(int l, int r){
            
            long long sum = 0;
            
            int bl = l/len , br = r/len;
            
            //if contained inside same block 
            if(bl == br){
                for(int i = l ; i <= r ; i++)sum+=arr[i];
            }else{
                //case when it spans multiple blocks or one block completely
                
                //left partial block
                for(int i = l , end = (bl+1)*len -1  ; i<= end ; i++) sum+=arr[i]; // (bl+1)*len give index of starting of next block and -1 gives the end index of current block
                
                //complete middle blocks
                for(int i = bl+1 ; i<= br-1 ; i++) sum+=blocks[i]; //whole blocks in between 
                //right parial block
                
                
                for(int i=br*len ; i<= r; i++)sum += arr[i]; //br*len gives starting index of last block 
            }
            
            
            return sum;
            
            
        }
};