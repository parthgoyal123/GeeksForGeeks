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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

bool findKeyPair(int *arr, int n, int sum) {
    unordered_map<int, int> hash;
    
    loop(i, 0, n) {
        if(hash.find(arr[i]) == hash.end()) {
            hash[arr[i]] = 1;
        } else {
            hash[arr[i]]++;
        }
        
        if(sum - arr[i] == arr[i] && hash[arr[i]] >= 2) return true;
        
        if(sum - arr[i] != arr[i] && hash.find(sum - arr[i]) != hash.end()) return true;
    }
    
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        
        bool exist = findKeyPair(arr, n, sum);
        if(exist) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}