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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

string getLongestPalindromeSubstring(string &s) {
    if(s.size() == 1) return s;
    
    int n = s.size();
    int max_len = INT_MIN;
    int l;
    int r;
    
    loop(i,0,n) {
        
        int left = i-1;
        int right = i+1;
        int curr_len = 1;
        
        while(left >= 0 && right < n && s[left] == s[right]) {
            curr_len += 2;
            left--;
            right++;
        }
        
        if(curr_len > max_len) {
            max_len = curr_len;
            l = left+1;
            r = right-1;
        }
        
        if(i+1 < n && s[i] == s[i+1]) {
            curr_len = 2;
            
            left = i-1;
            right = i+2;
            
            while(left >= 0 && right < n && s[left] == s[right]) {
                curr_len += 2;
                left--;
                right++;
            }
            
            if(curr_len > max_len) {
                max_len = curr_len;
                l = left+1;
                r = right-1;
            }
        }
    }
    
    // cout << l << " " << r << " " << max_len << endl;
    
    return s.substr(l, max_len);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        string s;
        cin >> s;
        string longest_palindrome = getLongestPalindromeSubstring(s);
        cout << longest_palindrome << endl;
    }
}