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

void stringIgnorance(string &str) {
    
    // make an hash table and we will alternate with 0 and 1
    unordered_map<char, int> map;
    
    for(int i = 0; i<str.length(); i++) {
        
        // convert to lower and check in map
        char c = tolower(str[i]);
        
        if(map.find(c) == map.end()) {
            cout << str[i];
            map[c] = 1;
        } else {
            map.erase(c);
        }    
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    
    // take care of enter
    string temp;
    getline(cin, temp);
    
    while(t--){
        string str;
        getline(cin, str, '\n');
        
        stringIgnorance(str);
        cout << endl;
    }
}