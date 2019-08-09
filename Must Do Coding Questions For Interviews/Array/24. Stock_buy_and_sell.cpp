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

void getMaxProfitDays(int *arr, int n) {
    
    if(n == 1) return;

    int i = 0;
    
    int start, end;
    
    bool flag = false;
    
    while(i < n-1) {
        
        // get the element whose next is bigger than current
        while(i < n-1 && arr[i+1] <= arr[i]) i++;
        
        // if reached last
        if(i == n-1) break;
        
        start = i++;
        
        // get the element whose next is smaller than current
        while(i < n && arr[i] >= arr[i-1]) i++;
        
        end = i-1;
        
        // indication that atleast one pair exists
        flag = true;
        
        cout << "(" << start << " " << end << ") ";
    }
    
    if(!flag) cout << "No Profit";
    
    return;
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
        
        getMaxProfitDays(arr, n);
        cout << endl;
    }
}