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
    
    int arr[n];
    
    loopr(i, n-1, 0) {
        int back_up = 0;
        loop(j, i, n){
            if(j == i) arr[j] = 1;
            else if (s[i] == s[j]) {
                int temp = arr[j];
                arr[j] = back_up + 2;
                back_up = temp;
            } else {
                back_up = arr[j];
                arr[j] = max(arr[j], arr[j-1]);
            }
        }
    }
    
    return arr[n-1];
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