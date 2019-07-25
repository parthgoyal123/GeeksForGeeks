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

bool compare(const pair<int, int> &pair1, const pair<int, int> &pair2) {
    if(pair1.second == pair2.second) {
        return pair1.first < pair2.first;
    }
    
    return pair1.second > pair2.second;
}

void sortByFrequency(int *arr, int n) {
    map<int, int, greater<int>> hash;
    
    loop(i,0,n) {
        hash[arr[i]]++;
    }
    
    int p = hash.size();
    
    pair<int, int> pairs[p];
    
    int j = 0;
    iterate(it, hash) {
        pairs[j] = make_pair(it->first, it->second);
        j++;
    }
    
    sort(pairs, pairs+p, compare);
    
    int index = 0;
    int i = 0;
    while(index < n && i < p) {
        int val = pairs[i].first;
        int count = pairs[i].second;
        
        while(count--) {
            arr[index] = val;
            index++;
        }
        i++;
    }
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
        
        sortByFrequency(arr, n);
        printArray(arr, n);
    }
}