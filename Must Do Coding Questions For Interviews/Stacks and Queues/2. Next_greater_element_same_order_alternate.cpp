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
    
    // use stack to always maintain the elements whose next greater is not found
    stack<ll int> s;
    
    // loop for rest elements
    for(int i=n-1; i>=0; i--) {
        
        // push arr[i] in the stack and pop all elements smaller than it
        while(!s.empty() && arr[i] > s.top()) {
            s.pop();
        }
        
        if(s.empty()) {
            greater[i] = -1;
        } else {
            greater[i] = s.top();
        }
        
        // push the current element in the stack    
        s.push(arr[i]);
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