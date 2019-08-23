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

void removeDuplicates(string &str) {
    
    // get the size of string
    int n = str.length();
    
    bool present[256] = {0};
    
    // complete the present array
    for(int i = 0; i< n; i++) {
        present[(int)str[i]] = true;
    }
    
    int index = 0;
    
    // get each character only once
    for(int i = 0; i<n; i++) {
        if(present[(int)str[i]]) {
            str[index++] = str[i];
            present[(int)str[i]] = false;
        }
    }
    
    str.erase(index);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    
    string temp;
    getline(cin, temp);
    
    while(t--){
        string str;
        getline(cin, str);
        
        removeDuplicates(str);
        cout << str << endl;
    }
}