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

bool canRearrangeCharacters(string &str) {
    
    // store frequency in hash table
    int hash[26] = {0};
    
    int max_freq = 0;
    
    // construct the frequency table
    for(int i = 0; i<str.length(); i++) {
        hash[str[i]-'a']++;
        
        max_freq = max(max_freq, hash[str[i]-'a']);
    }
    
    // now the max_freq should satisfy the condition
    if(max_freq <= (str.length() - max_freq + 1)) return true;
    
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << canRearrangeCharacters(str) << endl;
    }
}