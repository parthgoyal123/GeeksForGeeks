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

void reverseWords(string &s) {
    int n = s.size();
    
    // define the start and end index for reversing
    int start = 0;
    int end;
    
    loop(i,0,n) {
        
        // if next char is '.', then reverse from start to end
        if(s[i] == '.') {
            end = i; // end is exclusive
            reverse(s.begin() + start, s.begin() + end);
            start = i+1;
        }
    }
    
    // reverse the last word
    reverse(s.begin() + start, s.end());
    
    // reverse the whole string
    reverse(s.begin(), s.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        reverseWords(s);
        cout << s << endl;
    }
}