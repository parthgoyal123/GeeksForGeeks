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

void maximizeArray(int *a, int *b, int n) {
    int hash[10] = {0};
    int temp[n];
    
    loop(i,0,n) {
        if(hash[a[i]] == 0) hash[a[i]] = 1;
        if(hash[b[i]] == 0) hash[b[i]] = 1;
        
        temp[i] = a[i];
    }
    
    map<int, int> mp;
    
    int count = 0;
    int j = 9;
    while(count < n && j>=0) {
        if(hash[j] != 0 && mp.find(j) == mp.end()){
            mp[j] = 1;
            // cout << j << " ";
            count++;
        }
        j--;
    }
    
    int index = 0;
    int i = 0;
    while(index<n && i<n){
        if(mp.find(b[i]) != mp.end()) {
            a[index] = b[i];
            index++;
            mp.erase(b[i]);
        }
        i++;
    }
    j = 0;
    while(index<n && j<n) {
        if(mp.find(temp[j]) != mp.end()) {
            a[index] = temp[j];
            index++;
            mp.erase(temp[j]);
        }
        j++;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        loop(i,0,n) cin >> a[i];
        loop(i,0,n) cin >> b[i];
        
        maximizeArray(a, b, n);
        printArray(a, n);
    }
}