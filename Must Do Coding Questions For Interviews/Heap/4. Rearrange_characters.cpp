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

struct Key {
    char c;
    int count;
    
    bool operator<(const Key &k1) const {
        return this->count < k1.count;
    }
};

/* check if we can rearrange string such that no two same character are adjacent*/
bool canRearrangeCharacters(string &str) {
    
    int n = str.length();
    
    // store frequency in hash table
    int hash[26] = {0};
    
    int max_freq = 0;
    
    // construct the frequency table
    for(int i = 0; i<str.length(); i++) {
        hash[str[i]-'a']++;
    }
    
    priority_queue <Key> pq;
    for(int i = 0; i<26; i++) {
        char ch = i + 'a';
        if(hash[i] > 0) pq.push(Key{ch, hash[i]});
    }
    
    // final string
    str = "";
    
    // remember the previous Key
    Key prev{'#', -1};
    
    // traverse queue
    while(!pq.empty()) {
        
        // get the top character and append it to final string
        Key top = pq.top();
        pq.pop();
        str = str + top.c;
        
        // cout << top.c << " " << top.count << endl;
        
        // push to queue if previous count is > 0
        if(prev.count > 0) pq.push(prev);
        
        // decrease the count of the top element and update prev
        (top.count)--;
        prev = top;
    }
    
    if(n != str.length()) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << canRearrangeCharacters(str) << endl;
    }
}