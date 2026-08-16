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
        vector<vector<long long>>blocks;
        
        sqrtDecomposition(vector<long long>&a){
            n = a.size();
            len = sqrt(n+.0)+1;
            
            blocks.resize(len);
            arr = a;
            
            
            

            for (int i = 0; i < n; i++) {
                blocks[i / len].push_back(arr[i]);
            }
            
            for (int i = 0; i < len; i++) {
                sort(blocks[i].begin(), blocks[i].end());
            }
        }
        
        
        void update(int idx , long long val){
            
            int blockInd = idx / len;
            
            long long oldVal = arr[idx];
            
            auto it = lower_bound(blocks[blockInd].begin(), blocks[blockInd].end(),oldVal);
            
            *it = val;
            
            arr[idx] = val;
            
            sort(blocks[blockInd].begin(), blocks[blockInd].end());
        }
        
        
        long long greaterThanC(int l, int r, long long c){
            
            long long sum = 0;
            
            int bl = l/len , br = r/len;
            
            //if contained inside same block 
            if(bl == br){
                for(int i = l ; i <= r ; i++) arr[i] >= c ? sum+=1 : NULL;
            }else{
                //case when it spans multiple blocks or one block completely
                
                //left partial block
                for(int i = l , end = (bl+1)*len -1  ; i<= end ; i++) arr[i] >= c ? sum+=1 : NULL; // (bl+1)*len give index of starting of next block and -1 gives the end index of current block
                
                //complete middle blocks
                for(int i = bl+1 ; i<= br-1 ; i++){
                    int ind = lower_bound(
                        blocks[i].begin(),
                        blocks[i].end(),
                        c
                    ) - blocks[i].begin();
                
                    sum += blocks[i].size() - ind;
                }; //whole blocks in between 
                //right parial block
                
                
                for(int i=br*len ; i<= r; i++)arr[i] >= c ? sum+=1 : NULL; //br*len gives starting index of last block 
            }
            
            
            return sum;
            
            
        }
};

int main() {
	
	
	int n;
	cin>>n;
	
	vector<long long>arr(n);
	for(auto &it: arr) cin>>it;
	
	
	
	sqrtDecomposition sqrt1(arr);
	
	int q;
	cin>>q;
	
	while(q--){
	    int type;
	    cin>>type;
	    
	    
	    if(type == 0){
	        int l,r; 
	        long long c;
	        cin>>l>>r>>c;
	        cout<<sqrt1.greaterThanC(l-1,r-1,c)<<endl;
	    } else{
	        int idx;
	        long long val;
	        cin>>idx>>val;
	        sqrt1.update(idx-1,val);
	    }
	}
	
	
	
	
}
