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

int getIndex(string &str, string *roman) {
    
    for(int i = 0; i<13; i++) {
        if(str == roman[i]) return i;
    }
    
    // if not found in roman strings
    return -1;
}

int getRomanValue(string &str, string *roman, int *values) {
    
    // store the curr_value
    int curr_value = 0;
    
    string temp = "";
    
    // traverse through the string
    for(int i = 0; i<str.size(); ) {
        
        int index = -1;
        
        // get string of length 2 and check if that exists as a whole
        if(i+1 < str.size()) {
            temp = str.substr(i, 2);
            
            index = getIndex(temp, roman);
        }
        
        // if not found in size of 2, check for size of 1
        if(index == -1) {
            temp = str.substr(i,1);
            
            index = getIndex(temp, roman);
    
            curr_value += values[index];
            i++;
        } else {
            curr_value += values[index];
            i+=2;
        }
    }
    
    return curr_value;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    
    // roman values and strings
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] =  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    while(t--){
        string str;
        cin >> str;
        
        cout << getRomanValue(str, roman, values) << endl;
    }
}