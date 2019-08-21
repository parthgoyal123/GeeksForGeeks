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
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int count;
    int index;
    string key;
    
    TrieNode() {
        for(int i = 0; i<ALPHABET_SIZE; i++) {
            this->children[i] = NULL;
            this->isEndOfWord = false;
            this->count = 0;
            this->index = -1;
        }
    }
};

void insert(TrieNode *root, string &key, int ind) {
    
    // make a parent crawler to insert word
    TrieNode *pCrawl = root;
    
    // iterate through characters of string
    for(int i = 0; i<key.length(); i++) {
        
        // get index of string
        int index = key[i] - 'a';

        if(pCrawl->children[index] == NULL) {
            pCrawl->children[index] = new TrieNode();
        }
        
        pCrawl = pCrawl->children[index];
    }
    
    pCrawl->isEndOfWord = true;
    pCrawl->count += 1;
    pCrawl->key = key;
    
    // change the index to the first time occuring index
    if(pCrawl->index == -1) pCrawl->index = ind;
}

void getMaxCountStringUtil(TrieNode* root, int &maxx, string &s, int &ind) {
    
    // base case
    if(root == NULL) return;
    
    // check if count is greater than before
    if(root->isEndOfWord && root->count > maxx) {
        maxx = root->count;
        s = root->key;
        ind = root->index;
    } 
    
    // check if count is same, but it appeared before previous largest
    else if (root->isEndOfWord && root->count == maxx && root->index < ind) {
        s = root->key;
        ind = root->index;
    }
    
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        
        // check if children exists
        if(root->children[i]) {
            getMaxCountStringUtil(root->children[i], maxx, s, ind);
        }
    }
}

string getMaxCountString(TrieNode* root) {
    
    // define MAX
    int maxx = INT_MIN;
    string s;
    int ind = INT_MAX;
    
    // iterate for all root childrens (first character of every string)
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        
        // check if children exists
        if(root->children[i]) {
            getMaxCountStringUtil(root->children[i], maxx, s, ind);
        }
    }
    
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
            insert(root, word[i], i);
        }
        
        cout << getMaxCountString(root) << endl;
    }
}