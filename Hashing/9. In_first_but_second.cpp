#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopit(it, v) for(auto it = v.begin(); it != v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n,m;
        cin >> n >> m;
        ll int arr[n];
        ll int temp;
        unordered_set<ll int> hash;
        lloop(i,0,n){
            cin >> arr[i];
        }
        lloop(i,0,m){
            cin >> temp;
            hash.insert(temp);
        }
        
        lloop(i,0,n){
            if(hash.find(arr[i]) == hash.end()){
                cout << arr[i] << " ";
            }
        } cout << endl;
    }
}