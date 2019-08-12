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

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

void sortByFrequency(int *arr, int n) {
    
    // make a map to store all values frequencies
    map<int, int> m;
    
    loop(i,0,n) m[arr[i]]++;
    
    int s = m.size();
    
    // make pairs of distinct elements and their count
    pair<int, int> pairs[s];
    
    // put the values in pairs
    int i = 0;
    iterate(it, m) {
        pairs[i++] = mk(it->first, it->second);
    }
    
    // sort according to the compare function
    sort(pairs, pairs+s, compare);
    
    i = 0;
    
    // print the sorted pairs
    loop(j,0,m.size()) {
        while(pairs[j].second--) {
            arr[i++] = pairs[j].first;
        }
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