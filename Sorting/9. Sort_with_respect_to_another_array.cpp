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

void relativeSorting(int *a, int *b, int n, int m) {
    map<int, int> hash;
    
    loop(i,0,n){
        hash[a[i]]++;
    }
    
    int index = 0;
    loop(i,0,m){
        if(hash.find(b[i]) != hash.end()) {
            int count = hash[b[i]];
            while(count--) {
                a[index] = b[i];
                index++;
            }
            hash.erase(b[i]);
        }
    }
    
    iterate(it, hash){
        int count = it->second;
        while(count--){
            a[index++] = it->first;
        }
    }
    printArray(a, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n], brr[m];
        loop(i,0,n){
            cin >> arr[i];
        }
        loop(i,0,m) {
            cin >> brr[i];
        }
        
        relativeSorting(arr, brr, n, m);
    }
}