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

vector<int> getLeadersOfArray(int *arr, int n) {
    
    // define the leaders array
    vector<int> leaders;
    
    int index = 0;
    leaders.push_back(arr[n-1]);
    
    for(int i = n-2; i>=0; i--) {
        if(arr[i] >= leaders[index]) {
            leaders.push_back(arr[i]);
            index++;
        }
    }
    
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
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
        
        vector<int> leaders = getLeadersOfArray(arr, n);
        
        iterate(it, leaders) {
            cout << *it << " ";
        } cout << endl;
    }
}