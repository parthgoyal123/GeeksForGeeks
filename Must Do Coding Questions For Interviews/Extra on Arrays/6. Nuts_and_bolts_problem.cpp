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

int partition(char *arr, int low, int high, char pivot) {
    int i = low-1;
    
    for(int j = low; j<high; j++) {
        
        // similar to quicksort
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        } 
        
        // if we found correct match, swap it to last element
        else if (arr[j] == pivot) {
            swap(arr[j], arr[high]);
            j--;
        }
    }
    
    // arr[high] would contain matching to pivot, get it to correct position
    i++;
    swap(arr[i], arr[high]);
    
    return i;
}

/* Quick Sort modified implementation*/
void matchNutsAndBolts(char *nuts, char *bolts, int low, int high) {
    if(low < high) {
        
        // partition bolts array as per bolts[high]
        int pivot = partition(nuts, low, high, bolts[high]);
        
        // partition nuts array as per nuts[pivot]
        partition(bolts, low, high, nuts[pivot]);
        
        matchNutsAndBolts(nuts, bolts, low, pivot-1);
        matchNutsAndBolts(nuts, bolts, pivot+1, high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        loop(i,0,n) cin >> nuts[i];
        loop(i,0,n) cin >> bolts[i];
        
        matchNutsAndBolts(nuts, bolts, 0, n-1);
        printArray(nuts, n);
        printArray(bolts, n);
    }
}