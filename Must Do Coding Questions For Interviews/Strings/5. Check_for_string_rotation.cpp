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

bool rotated(string &s1, string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    
    if(n1 != n2) return false;
    
    string temp = s1 + s1;
    temp = temp.substr(2, n2);
    
    string temp2 = s2 + s2;
    temp2 = temp2.substr(2, n1);
    
    return (temp == s2) || (temp2 == s1);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        
        cout << rotated(s1, s2) << endl;
    }
}