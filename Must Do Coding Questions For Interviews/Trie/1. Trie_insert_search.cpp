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
    
    // pointer to its children
    TrieNode *children[ALPHABET_SIZE];
    
    // whether the node is end of word
    bool isEndOfWord;
    
    // constructor
    TrieNode() {
        this->isEndOfWord = false;
        for(int i = 0; i<ALPHABET_SIZE; i++) {
            this->children[i] = NULL;
        }
    }
};

void insertInTrie(TrieNode* root, string key) {
    
    // make a crawler to search for prefix and insert
    TrieNode* pCrawl = root;
    
    // loop through the string and check if prefix exists
    for(int i = 0; i<key.length(); i++) {
        
        // check for index of character and see if prefix exists
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) {
            pCrawl->children[index] = new TrieNode();
        }
        
        // crawl further down
        pCrawl = pCrawl->children[index];
    }
    
    // make last node as leaf
    pCrawl->isEndOfWord = true;
}

bool searchInTrie(TrieNode* root, string key) {
    
    // make a crawler to search for prefix and insert
    TrieNode* pCrawl = root;
    
    // loop through the string and check if prefix exists
    for(int i = 0; i<key.length(); i++) {
        
        // check for index of character and see if prefix exists
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) {
            return false;
        }
        
        // crawl further down
        pCrawl = pCrawl->children[index];
    }
    
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void viewAllWordsInTrieUtil(TrieNode* root, char* str, int level) {

    if(root == NULL) return;

    // check if its a leaf node or word ends here
    if(root->isEndOfWord == true) {
        str[level] = '\0';
        cout << str << endl;
    }

    for(int i = 0; i<ALPHABET_SIZE; i++) {

        // if child exists, add to str
        if(root->children[i]) {

            // get the character and append it to str
            str[level] = i + 'a';

            // recur for children
            viewAllWordsInTrieUtil(root->children[i], str, level+1);
        }
    }
}


void viewAllWordsInTrie(TrieNode *root) {

    // define level and curr string
    int level = 0;
    char str[50];

    viewAllWordsInTrieUtil(root, str, level);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string words[n];
        
        TrieNode* root = new TrieNode();
        
        loop(i,0,n) {
            cin >> words[i];
            insertInTrie(root, words[i]);
        }
        
        string key; cin >> key;
        
        cout << searchInTrie(root, key) << endl;
        
        viewAllWordsInTrie(root);
    }

}