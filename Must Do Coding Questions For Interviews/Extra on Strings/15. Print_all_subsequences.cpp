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

void printSubSeqRec(string &str, int n, int index = -1, string curr = "") { 
    // base case 
    if (index == n)  
        return; 
   
    if(curr != "") cout << curr << " "; 
    for (int i = index + 1; i < n; i++) { 
   
        curr += str[i]; 
        printSubSeqRec(str, n, i, curr); 
    
        // backtracking 
        curr = curr.erase(curr.size() - 1);  
    } 
    return; 
} 
   
// Generates power set in lexicographic 
// order. 
void printSubSeq(string &str) { 
    printSubSeqRec(str, str.size()); 
} 

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str; cin >> str;
        printSubSeq(str);
        cout << endl;
    }
}