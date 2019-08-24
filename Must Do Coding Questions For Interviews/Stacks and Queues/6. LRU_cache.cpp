#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}

/*
    Define global variables
*/

// keep cache key and value in cache (unordered_map)
unordered_map<int, int> cache;

// keep list (doubly linked list) for keeping lru
list<int> dq;

int capacity = 0;


/*Inititalize an LRU cache with size N */
LRUCache::LRUCache(int N) {
    
    // clear map and list
    cache.clear();
    dq.clear();
    capacity = N;
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int key, int value) {
    
    // check if key already exists in the map or not
    if(cache.find(key) == cache.end()) {
        // if not exist, check for capactiy
        
        // if capacity is also full
        if(dq.size() == capacity) {
            
            // pop the lru
            int lru = dq.back();
            dq.pop_back();
            
            // clear lru from map
            cache.erase(lru);
        }
        
        // do nothing, if capacity is not full
    } 
    
    // if already exists
    else {
        
        // erase prev position of key in list
        for(auto it = dq.begin(); it!= dq.end(); it++) {
            if(*it == key) {
                dq.erase(it);
                break;
            }
        }
    }
    
    // insert in map and list
    dq.push_front(key);
    cache[key] = value;
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x) {
    
    // check if key x exists
    if(cache.find(x) == cache.end()) return -1;
    
    // if key x exists, get key and update in list
    int value = cache[x];
    
    // erase prev position of key in list
    for(auto it = dq.begin(); it!= dq.end(); it++) {
        if(*it == x) {
            dq.erase(it);
            break;
        }
    }
    
    dq.push_front(x);
    
    return value;
}