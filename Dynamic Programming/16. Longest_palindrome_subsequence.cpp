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

int longestPalindromeSubsequence(string &s) {
    
    int n = s.size();
    int m = t.size();
    
    int count[m+1][n+1];
    
    loop(i,0,m+1) {
        loop(j,0,n+1) {
            if (i == 0 || j == 0) {
                count[i][j] = 0;
                continue;
            }
            if(s[j-1] != t[i-1]) {
                count[i][j] = max(count[i][j-1], count[i-1][j]);
            } else {
                count[i][j] = 1 + count[i-1][j-1];
            }
        }
    }
    return count[m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int longest_palindrome = longestPalindromeSubsequence(s);
        cout << longest_palindrome << endl;
    }
}