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
 
vector<int> pref;
vector<tuple<int,int,int>> queries;
 
static bool cmp(
const tuple<int,int,int>& a,
const tuple<int,int,int>& b){
 
    int l1=get<0>(a);
    int r1=get<1>(a);
 
    int l2=get<0>(b);
    int r2=get<1>(b);
 
    int block1=l1/block;
    int block2=l2/block;
 
    if(block1!=block2)
        return block1<block2;
 
    return (block1&1)
        ? r1>r2
        : r1<r2;
}
 
long long answer=0;
 
const int MAXX=(1<<20)+5;
 
vector<int> freq(MAXX);
 
int K;
 
void Add(int idx){
 
    int x=pref[idx];
 
    answer+=freq[x^K];
 
    freq[x]++;
}
 
void Remove(int idx){
 
    int x=pref[idx];
 
    freq[x]--;
 
    answer-=freq[x^K];
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
 
    cin>>n>>q>>K;
 
    vector<int> arr(n);
 
    for(int&i:arr)
        cin>>i;
 
    pref.resize(n+1);
 
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]^arr[i-1];
 
    block=sqrt(n+1);
 
    for(int i=0;i<q;i++){
 
        int l,r;
 
        cin>>l>>r;
 
        queries.push_back({
            l-1,
            r,
            i
        });
    }
 
    sort(
        queries.begin(),
        queries.end(),
        cmp
    );
 
    vector<long long> ans(q);
 
    int currL=0;
    int currR=-1;
 
    for(auto [L,R,idx]:queries){
 
        while(currL>L)
            Add(--currL);
 
        while(currR<R)
            Add(++currR);
 
        while(currL<L)
            Remove(currL++);
 
        while(currR>R)
            Remove(currR--);
 
        ans[idx]=answer;
    }
 
    for(auto x:ans)
        cout<<x<<"\n";
}