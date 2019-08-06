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

string longestPalindromeSubstring(string &s) {
    
    // initialize the required var
    int left, right;
    
    int n = s.size();
    
    // final left indices 
    int l_final, max_length = INT_MIN;
    
    // loop for all indices
    loop(curr, 0, n) {
        
        // check for odd length palindrome
        left = curr-1;
        right = curr+1;
        
        int curr_length_odd = 1;
        
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
            curr_length_odd += 2;
        }
        
        if(curr_length_odd > max_length) {
            max_length = curr_length_odd;
            l_final = left+1;
        }
        
        int curr_length_even = INT_MIN;
        
        // check for even length palindrome
        if(curr < n-1 && s[curr] == s[curr+1]) {
            left = curr-1;
            right = curr+2;
            
            curr_length_even = 2;
            
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                curr_length_even += 2;
            }
            
            if(curr_length_even > max_length) {
                max_length = curr_length_even;
                l_final = left+1;
            }
        }
    }
    
    return s.substr(l_final, max_length);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        cout << longestPalindromeSubstring(s) << endl;
    }
}