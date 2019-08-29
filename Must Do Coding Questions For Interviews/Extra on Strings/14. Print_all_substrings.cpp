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
#define ALPHABET_SIZE 26

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

void printAllSubstrings(string &str) {
    // get the length of the string
    int n = str.length();

    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
            cout << str.substr(i, j-i+1) << " ";
        }
    }
}

void printAllSubstringsLength(string &str) {
    // get length of the string
    int n = str.length();

    // for all lengths ranging from 1 to N
    for(int L = 1; L <= n; L++) {

        // for all possible starting points
        for(int i = 0; i<n-L+1; i++) {
            cout << str.substr(i, L) << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str; cin >> str;

        printAllSubstrings(str);
        cout << endl;
        printAllSubstringsLength(str);
        cout << endl;
    }
}