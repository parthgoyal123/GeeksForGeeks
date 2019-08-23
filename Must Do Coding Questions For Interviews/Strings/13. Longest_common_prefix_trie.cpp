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

struct Node{
    unordered_map<char, Node*> map;
    bool isLeaf;
    Node() {
        this->isLeaf = false;
    }
};

void insertInTrie(Node* root, string &str) {
    
    // make a crawler to search for prefix and insert
    Node* pCrawl = root;
    
    // loop through the string and check if prefix exists
    for(int i = 0; i<str.length(); i++) {
        
        // check for index of character and see if prefix exists
        if(pCrawl->map.find(str[i]) == pCrawl->map.end()) {
            pCrawl->map[str[i]] = new Node();
        }
        
        // crawl further down
        pCrawl = pCrawl->map[str[i]];
    }
    
    // make last node as leaf
    pCrawl->isLeaf = true;
}

string getLongestPrefix(Node* root) {
    
    // make a crawler
    Node *pCrawl = root;
    
    string str = "";
    
    int curr_length = 0;
    
    while(pCrawl != NULL) {
        
        // if map consists of more than one child
        if(pCrawl->map.size() != 1 && str == "") return "-1";
        if(pCrawl->map.size() != 1) return str;
        
        // size should be one
        else if (pCrawl->map.size() == 1) {
            
            // get the only character map
            auto it = pCrawl->map.begin();
            
            string temp(1, it->first);
            
            // append it to string
            str.append(temp);
            
            // move parent crawler down
            pCrawl = it->second;
        }
        
        if(pCrawl->isLeaf) return str;
    }
    
    return "-1";
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        Node *root = new Node();
        
        int n; cin >> n;
        loop(i,0,n) {
            string temp;
            cin >> temp;
            
            insertInTrie(root, temp);
        }
        
        cout << getLongestPrefix(root) << endl;
    }
}