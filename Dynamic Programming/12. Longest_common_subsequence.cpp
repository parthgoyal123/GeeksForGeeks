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

int longestSubsequenceLength(string s, string t) {
    int n = s.size();
    int m = t.size();
    
    int count[m+1][n+1];
    
    loop(i,0,m+1) count[i][0] = 0;
    loop(i,0,n+1) count[0][i] = 0;
    
    loop(i,1,m+1) {
        loop(j,1,n+1) {
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
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        
        cout << longestSubsequenceLength(s, t) << endl;
    }
}