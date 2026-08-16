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


int block;

vector<int>arr;
vector<tuple<int,int,int>>queries;

static bool cmp(tuple<int,int,int>&a, tuple<int,int,int>&b){
    int l1 = get<0>(a);
    int r1 = get<1>(a);

    int l2 = get<0>(b);
    int r2 = get<1>(b);

    int block1 = l1 / block;
    int block2 = l2 / block;

    if (block1 != block2)
        return block1 < block2;

    if (block1 & 1)
        return r1 > r2;

    return r1 < r2;
}

int res=0;
unordered_map<int,int>freq;

void Add(int ind){
    int num = arr[ind];
    if(freq[num] == 0) res++;
    freq[num]++;
}

void Remove(int ind){
    int num = arr[ind];
    freq[num]--;
    if(freq[num] == 0) res--;
}



int main() {
	
    int n;
    cin>>n;
    
    block = sqrt(n);
    arr.resize(n);
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    
    int q;
    cin>>q;
    
    for(int i=0 ; i< q ; i++){
        
        int l,r;
        cin>>l>>r;
        
        queries.push_back({l-1,r-1,i});
        
    }
    
    sort(queries.begin(),queries.end(),cmp);
    
    int currL=0, currR=-1;
    
    vector<int>ans(q,0);
    
    for(auto [L,R,ind] : queries){
        
        while(currL > L)
            Add(--currL);
            
        while(currR > R)
            Remove(currR--);
            
        while(currL < L)
            Remove(currL++);
            
        while(currR < R)
            Add(++currR);
            
        ans[ind] = res;
        
        
        
    }
    
    
    for(int i: ans)cout<<i<<" ";
    
    
    

}
