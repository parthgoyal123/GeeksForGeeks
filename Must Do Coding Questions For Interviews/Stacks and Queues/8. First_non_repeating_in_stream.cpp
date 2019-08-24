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

void getNonRepeatingStream(char *arr, int n) {
    
    // base conditions
    if(n == 1) cout << arr[0] << endl;
    
    // stores characters in queue
    queue <char> q;
    
    // add first character
    q.push(arr[0]);
    
    unordered_map <char, int> hash;
    
    hash[arr[0]] = 1;
    
    cout << arr[0] << " ";
    
    // loop for all rest elements
    for(int i = 1; i<n; i++) {
        
        // add to hash and push to queue if first occurence
        if(hash.find(arr[i]) == hash.end()) {
            hash[arr[i]] = 1;
            q.push(arr[i]);
        } else {
            hash[arr[i]]++;
        }
        
        // check for non-repeating
        if(hash[q.front() - 'a'] == 1) {
            cout << q.front() << " ";
        } 
        
        else {
            
            // pop elements until their count
            while(!q.empty() && hash[q.front()] > 1) {
                q.pop();
            }
            
            // check if queue is empty or not
            if(q.empty()) cout << -1 << " ";
            else cout << q.front() << " ";
        }
    }
    
    cout << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char arr[n];
        loop(i,0,n) cin >> arr[i];
        
        getNonRepeatingStream(arr, n);
    }
}