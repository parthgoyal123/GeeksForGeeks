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

int minInsertions(string &str, int l, int h) {
    
    // base conditions
    if(l > h) return INT_MAX;
    
    // if one character is checked
    if(l == h) return 0;
    
    // if two characters are to be checked
    if(l == (h-1)) return (str[l] == str[h])? 0:1;
    
    // if last characters are same
    if(str[l] == str[h]) {
        return minInsertions(str, l+1, h-1);
    }
    
    return min(minInsertions(str, l+1, h), minInsertions(str, l, h-1)) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << minInsertions(str, 0, str.length()-1) << endl;
    }
}