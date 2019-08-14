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

int getMax(int *arr, int n, int sum) {
    
    sort(arr, arr+n);
    
    int curr_sum = arr[0];
    int count = 0;
    
    loop(i,1,n) {
        if(curr_sum > sum) break;
        
        else {
            count++;
            curr_sum += arr[i];
        }
    }
    
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << getMax(arr, n, sum) << endl;
    }
}