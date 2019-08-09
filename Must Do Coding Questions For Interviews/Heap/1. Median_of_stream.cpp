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

void printMedians(int *arr, int n) {
    if(n == 1) {
        cout << arr[0] << endl;
        return;
    }
    
    // Make min and smaller_maxHeaps
    
    // smaller_maxHeap to store smaller half elements
    priority_queue<double> smaller_maxHeap;
    
    // greater_minHeap to store greater half elements
    priority_queue<double, vector<double>, greater<double>> greater_minHeap;
    
    // push the first element and initialze the curr median with first element
    smaller_maxHeap.push(arr[0]);
    double curr_median = arr[0];
    
    cout << curr_median << " ";
    
    // reading elements of stream one by one 
    /*  At any time we try to make heaps balanced and 
        their sizes differ by at-most 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top() 
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */
    loop(i,1,n) {
        double num = arr[i];
        
        // see if the size of both heaps is same or not
        if (smaller_maxHeap.size() == greater_minHeap.size()) {
            if(num < curr_median) {
                smaller_maxHeap.push((double) num);
                curr_median = (double) smaller_maxHeap.top();
            } else {
                greater_minHeap.push((double) num);
                curr_median = (double) greater_minHeap.top();
            }
        } 
        
        // if size of greater_minHeap is less than smaller_maxHeap (left side has more elements)
        else if(smaller_maxHeap.size() > greater_minHeap.size()) {
            if(num < curr_median) {
                greater_minHeap.push(smaller_maxHeap.top());
                smaller_maxHeap.pop();
                smaller_maxHeap.push(num);
            } else {
                greater_minHeap.push(num);
            }
            
            curr_median = (smaller_maxHeap.top() + greater_minHeap.top())/2.0;
        }
        
        // if greater side has more elements
        else {
            if(num > curr_median) {
                smaller_maxHeap.push(greater_minHeap.top());
                greater_minHeap.pop();
                greater_minHeap.push(num);
            } else {
                smaller_maxHeap.push(num);
            }
            
            curr_median = (smaller_maxHeap.top() + greater_minHeap.top())/2.0;
        }
        
        cout << curr_median << " ";
    }
    
    cout << endl;
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
        
        printMedians(arr, n);
    }
}