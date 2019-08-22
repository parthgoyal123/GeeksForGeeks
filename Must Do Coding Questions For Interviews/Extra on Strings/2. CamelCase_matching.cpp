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

struct TrieNode {
    
    // only Capital letters
    TrieNode* children[ALPHABET_SIZE];
    bool isLeaf;
    
    // store all the words
    list<string> word;
    
    TrieNode() {
        for(int i = 0; i<ALPHABET_SIZE; i++) {
            this->children[i] = NULL;
            this->isLeaf = false;
        }
    }
};

void insert(TrieNode* root, string &key) {
    
    // make a crawler
    TrieNode *crawl = root;
    
    // traverse through all characters of key
    for(int i=0; i<key.length(); i++) {
        
        // insert only for capital letters
        if(key[i] >= 'A' && key[i] <= 'Z') {
            
            int index = key[i] - 'A';
            
            // check if children node exists
            if(crawl->children[index] == NULL) {
                crawl->children[index] = new TrieNode();
            }
            
            // crawl deeper
            crawl = crawl->children[index];
        }
    }
    
    crawl->isLeaf = true;
    crawl->word.push_back(key);
}

void printAllWords(TrieNode* root) {
    
    if(root == NULL) return;
    
    // check if it is a leaf
    if(root->isLeaf) {
        for(auto it : root->word) {
            cout << it << " ";
        }
    }
    
    // printWords corresponding to all childrens
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        if(root->children[i]) {
            printAllWords(root->children[i]);
        }
    }
}

void printWordsWithPattern(TrieNode* root, string &pattern) {
    TrieNode *crawl = root;
    for(int i = 0; i<pattern.size(); i++) {
        int index = pattern[i] - 'A';
        if(crawl->children[index] == NULL) {
            cout << "No match found" << endl;
            return;
        }
        crawl = crawl->children[index];
    }
    
    printAllWords(crawl);
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        
        TrieNode* root = new TrieNode();
        
        loop(i,0,n) {
            cin >> arr[i];
            insert(root, arr[i]);
        }
        
        string pattern;
        cin >> pattern;
        
        printWordsWithPattern(root, pattern);
    }
}