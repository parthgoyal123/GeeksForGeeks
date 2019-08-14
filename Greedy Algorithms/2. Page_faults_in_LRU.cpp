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

int getPageFaults(int *arr, int n, int c) {
    
    // get the total number of page faults
    int faults = 0;
    
    // stores which pages are currently in the memory
    unordered_set<int> s;
    
    // stores the very recent occurence of any page
    unordered_map<int, int> index;
    
    loop(i,0,n) {
        
        // if the memory is not full
        if(s.size() < c) {
            
            // find if the page exists in the memory or not
            if(s.find(arr[i]) == s.end()) {
                s.insert(arr[i]);
                faults++;
            }
            
            index[arr[i]] = i;
        }
        
        // else if memory is full
        else {
            
            // check if the new page exists in the memory or not
            if(s.find(arr[i]) == s.end()) {
                
                // Find the least recently used pages 
                // that is present in the set 
                int lru = INT_MAX, val; 
                for (auto it = s.begin(); it!=s.end(); it++) { 
                    if (index[*it] < lru) { 
                        lru = index[*it]; 
                        val = *it; 
                    } 
                } 
  
                // Remove the indexes page 
                s.erase(val); 
  
                // insert the current page 
                s.insert(arr[i]); 
  
                // Increment page faults 
                faults++; 
            }
            
            index[arr[i]] = i;
        }
    }
    
    return faults;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        int c; cin >> c;
        
        cout<<getPageFaults(arr, n, c)<< endl;
    }
}