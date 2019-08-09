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

void relativeSort(int *a, int n, int *b, int m) {
    map<int, int> hash;
    
    // hash all the elements of array1
    loop(i,0,n) {
        if(hash.find(a[i]) == hash.end())
            hash[a[i]] = 1;
        else 
            hash[a[i]]++;
    }
    
    int ind = 0;
    
    // loop for all the elements of array2
    loop(i,0,m) {
        
        // if found in hash, insert in array1
        if(hash.find(b[i]) != hash.end()) {
            int num = hash[b[i]];
            while(num--) {
                a[ind++] = b[i];
            }
            
            // remove the key from hash
            hash.erase(b[i]);
        }
    }
    
    // insert rest of the elements in increasing order
    iterate(it, hash) {
        int num = it->second;
        while(num--) {
            a[ind++] = it->first;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        loop(i,0,n) cin >> a[i];
        loop(i,0,m) cin >> b[i];
        
        relativeSort(a, n, b, m);
        printArray(a, n);
    }
}