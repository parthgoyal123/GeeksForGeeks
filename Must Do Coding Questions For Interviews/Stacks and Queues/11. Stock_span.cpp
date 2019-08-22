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

void calculateStockSpan(int *stock, int *span, int n) {
    
    // store greater values "index" in stack
    stack<int> st;
    
    int index = 0;
    
    st.push(index);
    span[index++] = 1;
    
    for(int i = 1; i<n; i++) {
        
        // pop elements in stock with lesser stock values
        while(!st.empty() && stock[st.top()] <= stock[i]) {
            st.pop();
        }
        
        // calculate span for next index
        span[index++] = (st.empty() == true)? i+1 : i - st.top();
        
        st.push(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int stock[n];
        loop(i,0,n) cin >> stock[i];
        int span[n];
        
        calculateStockSpan(stock, span, n);
        printArray(span, n);   
    }
}