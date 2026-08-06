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


class Node {
public:
    bool flag;
    vector<Node*> links;

    Node() {
        flag = false;
        links.assign(26, nullptr);
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }

    ~Node(){
        for(Node *node: links){
            delete node;
        }
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
        
        
        void insert(string word){
            Node *node = root;
            
            for(char ch: word){
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                
                node = node->get(ch);
            }
            
            node->setEnd();
        }
        
        
        
        bool search(string word){
            Node *node = root;
            for(char ch: word){
                if(!node->containsKey(ch)) return false;
                
                node = node->get(ch);
            }
            
            return node->isEnd();
        }
        
        
        bool searchPrefix(string word){
            Node *node = root;
            
            for(char ch: word){
                if(!node->containsKey(ch)) return false;
                
                node = node->get(ch);
            }
            
            
            return true;
        }
};





