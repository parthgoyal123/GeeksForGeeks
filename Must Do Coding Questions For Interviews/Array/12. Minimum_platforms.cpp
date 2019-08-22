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

int getMinPlatforms(int *arr, int *dep, int n) {
    
    // sort arrival and dept times
    sort(arr, arr+n);
    sort(dep, dep+n);
    
    // increase on arrival and decrease on dept
    int curr_plat = 0;
    
    int i = 0, j = 0;
    
    // get max platform at a time
    int max_plat = 0;
    
    // iterate through all arrival and dept time
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            curr_plat ++;
            i++;
        } else {
            curr_plat--;
            j++;
        }
        
        max_plat = max(max_plat, curr_plat);
    }
    
    return max_plat;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int arrive[n], dep[n];
        loop(i,0,n) cin >> arrive[i];
        loop(i,0,n) cin >> dep[i];
        
        // now we have times in sorted form, lets calculate min platforms
        cout << getMinPlatforms(arrive, dep, n) << endl;
    }
}