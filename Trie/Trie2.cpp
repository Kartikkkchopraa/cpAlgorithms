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
        int ew,cp;

        Node(){
            links.assign(26,nullptr);
            ew=cp=0;
        }

        ~Node(){
            for(Node * child: links) delete child;
        }


        bool containsKey(char ch){
            return links[ch-'a'] != nullptr;
        }

        void put(char ch , Node* node){
            links[ch-'a'] = node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void increaseEnd(){
            ew++;
        }

        void increasePrefix(){
            cp++;
        }

        void deleteEnd(){
            ew--;
        }

        void reducePrefix(){
            cp--;
        }
        
        
};



class Trie{
    private:
        Node *root;
    public:

        Trie(){
            root = new Node();
        }

        ~Trie(){
            delete root;
        }


        void insert(string &word){
            Node *node = root;
            for(char ch: word){
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node = node->get(ch);
                node->increasePrefix();
                
            }

            node->increaseEnd();
        }


        int countWordsEqualTo(string &word){
            Node *node = root;

            for(char ch: word){
                if(!node->containsKey(ch)) return 0;
                node = node->get(ch);
            }

            return node->ew;
        }


        int countWordsStartingWith(string &word){
            


            Node *node = root;

            for(char ch: word){
                if(!node->containsKey(ch)) return 0;
                node=node->get(ch);
            }


            return node->cp;
        }


        void erase(string &word){
            if (countWordsEqualTo(word) == 0) return;
            Node *node = root;
            for(char ch: word){
                node = node->get(ch);
                node->reducePrefix();
            }

            node->deleteEnd();
        }

};