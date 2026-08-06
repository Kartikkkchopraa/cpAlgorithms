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

class Node{
    public:
        vector<Node*>links;
        
        Node(){
            links.assign(2,nullptr);
        }
        
        bool containsKey(int bit){
            return links[bit] != nullptr;
        }
        
        void put(int bit,Node* node){
            links[bit] = node;
        }
        
        Node* get(int bit){
            return links[bit];
        }
        
        ~Node() {
            for (Node* child : links)
                delete child;
        }
        
        
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        
        ~Trie(){
            delete root;
        }
        
        void insert(int num){
            Node* node = root;
            
            for(int i = 31 ; i>=0 ; i--){
                int bit = (num >> i) & 1;
                
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                
                node = node->get(bit);
            }
        }
        
        
        int getMax(int num){
            Node* node = root;
            int ans = 0;
            for(int i=31 ; i >=0 ; i--){
                int bit = (num >> i) & 1;
                
                int requireBit = bit ^ 1;
                
                if(node->containsKey(requireBit)){
                    ans |= (1<<i);
                    
                    node= node->get(requireBit);
                }else{
                    node = node->get(bit);
                }
                
                
            }
            
            return ans;
        }
};