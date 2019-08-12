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

set<vector<int>> getPossibleQuadraples(int *arr, int n, int sum) {
    // for invalid input
    if(n < 4) return set<vector<int>>();
    
    // get sum of all pairs in array
    multimap<int, pair<int, int>> m;
    
    loop(i,0,n-1) {
        loop(j,i+1,n) {
            int curr_sum = arr[i] + arr[j];
            m.insert(mk(curr_sum, mk(i, j)));
        }
    }
    
    // vector array of answers
    set<vector<int>> ans;
    
    // iterate through the multimap
    for(auto it = m.begin(); it!= m.end(); it++) {
        
        // get the sum of the two array elements
        int curr_sum = it->first;
        
        // get indices
        pair<int, int> p1 = it->second;
        
        // required sum now
        int req_sum = sum - curr_sum;
        
        // check in the multimap
        
        // if present in the map
        if(m.find(req_sum) != m.end()) {
            
            // get the lower and upper bounds of the req_sum
            auto it1 = m.lower_bound(req_sum);    
            auto it2 = m.upper_bound(req_sum);
            
            while(it1 != it2) {
                
                pair<int, int> p2 = it1->second;
                
                // check if this have no common indices
                if(p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second) {
                    vector<int> ind;
                    ind.pb(arr[p1.first]);
                    ind.pb(arr[p2.first]);
                    ind.pb(arr[p1.second]);
                    ind.pb(arr[p2.second]);
                    
                    // sort the vector int and add it to ans vector
                    sort(ind.begin(), ind.end());
                    ans.insert(ind);
                    
                    // clear the vector
                    ind.clear();
                }
                
                it1++;
            }
        }
    }
    
    return ans;
    
}

void printQuad(set<vector<int>> &quad) {
    if(quad.size() == 0) {
        cout << -1 << endl;
        return;
    }
    
    for(auto it = quad.begin(); it != quad.end(); it++) {
        for(auto it1 = it->begin(); it1 != it->end(); it1++) {
            cout << *it1 << " ";
        } cout << "$";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        set<vector<int>> quad = getPossibleQuadraples(arr, n, k);
        
        printQuad(quad);
    }
}