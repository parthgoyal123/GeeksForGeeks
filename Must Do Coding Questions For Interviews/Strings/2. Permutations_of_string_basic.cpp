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

void getPermutations(string &s, int l, int r, set<string> &strings) {
    
    // base case
    if(l == r) {
        strings.insert(s);
        return;
    }
    
    // swap for every case and permute
    for(int i = l; i<=r; i++) {
        swap(s[l], s[i]);
        getPermutations(s, l+1, r, strings);
        swap(s[l], s[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        int n = s.size();
        sort(s.begin(), s.end());
        
        set<string> strings;
        getPermutations(s, 0, n-1, strings);
        
        iterate(it, strings) {
            cout << *it << " ";
        }
        
        cout << endl;
    }
}