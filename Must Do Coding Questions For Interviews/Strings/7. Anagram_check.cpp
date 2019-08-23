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

bool checkIfAnagrams(string &s1, string &s2) {
    // make hashtable for s1 and check for s2
    int hash[26] = {0};
    
    for(int i = 0; i<s1.length(); i++) {
        hash[s1[i] - 'a']++;
    }
    
    // check for every character in s2
    for(int i = 0; i<s2.length(); i++) {
        if(hash[s2[i] - 'a'] == 0) return false;
        else {
            hash[s2[i] - 'a']--;
        }
    }
    
    // check the hash table
    for(int i = 0; i<26; i++) {
        if(hash[i] < 0 || hash[i] > 0) return false;
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        
        if(checkIfAnagrams(s1, s2)) cout << "YES";
        else cout << "NO";
        
        cout << endl;
    }
}