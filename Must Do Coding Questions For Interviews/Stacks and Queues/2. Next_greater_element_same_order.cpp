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
#define pli pair<long long int, int>

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

void nextLargerElement(ll int *arr, int n) {
    
    if(n == 0) return;
    
    // make an array that stores next greater
    ll int greater[n];
    memset(greater, -1, sizeof(greater));
    
    // use stack to always maintain the elements whose next greater is not found
    stack<pli> s;
    
    s.push({arr[0], 0});
    
    // loop for rest elements
    for(int i=1; i<n; i++) {
        
        // push arr[i] in the stack and pop all elements smaller than it
        pli top = s.top();
        while(!s.empty() && arr[i] > top.first) {
            greater[top.second] = arr[i];
            s.pop();
            if(!s.empty()) top = s.top();
        }
        
        // push the current element in the stack    
        s.push({arr[i], i});
    }
    
    printArray(greater, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        nextLargerElement(arr, n);
    }
}