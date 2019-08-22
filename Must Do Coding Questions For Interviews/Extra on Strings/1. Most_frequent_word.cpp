#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back
#define ALPHABET_SIZE 26

template <typename T>
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

struct TrieNode{
    string key;
    int count;
    unordered_map<char, TrieNode*> map;
    
    TrieNode() {
        this->count = 0;
    }
};

void insert(TrieNode *root, string &key) {
    
    // make a parent crawler to insert word
    TrieNode *pCrawl = root;
    
    // iterate through characters of string
    for(int i = 0; i<key.length(); i++) {
        
        // get index of string
        char index = key[i];

        // find the current char in the map of children nodes
        if(pCrawl->map.find(index) == pCrawl->map.end()) {
            pCrawl->map[index] = new TrieNode();
        }
        
        pCrawl = pCrawl->map[index];
    }
    
    pCrawl->count += 1;
    pCrawl->key = key;
}

void getMaxCountStringUtil(TrieNode* root, int &maxx, string &s) {
    
    // base case
    if(root == NULL) return;
    
    // traverse through the map
    for(auto it : root->map) {
        
        // update maxx count value and string s
        if(it.second->count > maxx) {
            maxx = it.second->count;
            s = it.second->key;
        }
        
        // call util function for children nodes
        getMaxCountStringUtil(it.second, maxx, s);
    }
}

string getMaxCountString(TrieNode* root) {
    
    // define MAX
    int maxx = 0;
    string s;
    
    // get the count and string
    getMaxCountStringUtil(root, maxx, s);
    
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string word[n];
        
        TrieNode *root = new TrieNode();
        
        for(int i =0;i<n; i++) {
            cin >> word[i];
            insert(root, word[i]);
        }
        
        cout << getMaxCountString(root) << endl;
    }
}