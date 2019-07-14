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

int getMinimumDistance(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    
    int count[m+1][n+1];
    
    loop(row,0,m+1) {
        loop(col,0,n+1) {
            if(row == 0) {
                count[row][col] = col;
            } else if(col == 0) {
                count[row][col] = row;
            } else if(t[row-1] == s[col-1]) {
                count[row][col] = count[row-1][col-1];
            } else {
                count[row][col] = 1 + min(count[row][col-1], min(count[row-1][col], count[row-1][col-1]));
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
        
        cout << getMinimumDistance(s, t) << endl;
    }
}