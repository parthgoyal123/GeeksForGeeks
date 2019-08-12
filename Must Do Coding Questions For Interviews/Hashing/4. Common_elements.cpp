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

void printIntersections(ll int *a, ll int n1, ll int *b, ll int n2, ll int *c, ll int n3) {
    ll int i = 0, j = 0, k = 0;
    
    bool flag = false;
    
    ll prev = INT_MIN;
    
    // traverse the array
    while(i < n1 && j < n2 && k < n3) {
        
        // if all the three elements are equal
        if(a[i] == b[j] && b[j] == c[k] && a[i] != prev) {
            cout << a[i] << " ";
            flag = true;
            prev = a[i];
            i++; j++; k++;
        }
        
        // if the first array element is smaller than second array element
        else if(a[i] < b[j]) i++;
        
        // second array element is smaller than third and first
        else if(b[j] < c[k]) j++;
        
        // third array element is the smallest
        else k++;
    }
    
    if(!flag) cout << -1;
    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        ll int a[n1], b[n2], c[n3];
        lloop(i,0,n1) cin >> a[i];
        lloop(i,0,n2) cin >> b[i];
        lloop(i,0,n3) cin >> c[i];
        
        printIntersections(a, n1, b, n2, c, n3);
    }
}