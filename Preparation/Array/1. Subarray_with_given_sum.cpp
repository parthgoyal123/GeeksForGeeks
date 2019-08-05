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

void getPositions(int *arr, int n, int s) {
    
    // return if only one element exits
    if(n == 1) {
        cout << -1 << endl;
    }
    
    // get curr_sum
    int curr_sum = 0;
    int max_sum = 0;
    
    // intialize the starting and ending index of the array
    int start = 0;
    int end = INT_MIN;
    
    // loop through the array
    loop(i,0,n) {
        
        // add the current element to the sum and check if curr_sum is the required sum
        curr_sum += arr[i];
        
        if(curr_sum == s) {
            end = i;
            cout << start+1 << " " << end+1 << endl;
            return;
        }
        
        // if the new curr_sum exceeds the sum s, remove the starting elements and increment the starting index
        while(curr_sum > s) {
            curr_sum -= arr[start++];
            if(curr_sum == s) {
                end = i;
                cout << start+1 << " " << end+1 << endl;
                return;
            }
        }
    }
    
    // print -1 if not found s
    cout << -1 << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        getPositions(arr, n, s);
    }
}