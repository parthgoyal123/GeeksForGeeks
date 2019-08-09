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

void getCombinationsUtil(int *arr, int ind, int n, int curr_sum, int sum, set<vector<int>> &vec, vector<int> v) {
    
    // if the current sum is equal to current sum, push 
    if(curr_sum == sum) {
        vec.insert(v);
        
        // iterate(it, v) {
        //     cout << *it << " ";
        // }
        // cout << endl;
        
    } 
    
    // if the curr_sum has exceeded the required sum limit
    else if (curr_sum > sum) {
        return;
    } 
    
    // if the current sum is still less than required sum
    else {
        
        // check for index of the array
        if(ind < n) {
            
            // push the current index array element and increment curr_sum
            v.pb(arr[ind]);
            getCombinationsUtil(arr, ind+1, n, curr_sum + arr[ind], sum, vec, v);
            
            // pop the current index array and don't disturb the curr_sum
            v.pop_back();
            getCombinationsUtil(arr, ind+1, n, curr_sum, sum, vec, v);
            
        }
    }
}

void getCombinations(int *arr, int n, int sum) {
    
    // sort the array in non-decreasing order first
    sort(arr, arr+n);
    
    set<vector<int>> vec;
    
    vector<int> v;
    
    getCombinationsUtil(arr, 0, n, 0, sum, vec, v);
    
    if(vec.size() == 0) {
        cout << "Empty" << endl;
        return;
    }
    
    for(auto it = vec.begin(); it!= vec.end(); it++) {
        cout << "(";
        int si = it->size();
        loop(i,0,si-1) cout << (*it)[i] << " ";
        cout << (*it)[si-1];
        cout << ")";
    } cout << endl;
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
        
        int sum; cin >> sum;
        
        getCombinations(arr, n, sum);
    }
}