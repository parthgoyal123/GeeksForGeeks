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

bool presentInDictionary(string *s, int n, string x) {
    loop(i,0,n) {
        if(x == s[i]) return true;
    }
    return false;
}

bool canBreakIntoWords(string &s, string* arr, int n) {
    int len = s.size();
    
    bool dp[len] = {0};
    int left = 0;
    int right = 0;
    
    loop(i,0,len) {
        string t = s.substr(left, i-left+1);
        if(presentInDictionary(arr, n, t)) {
            left = i+1;
        }
    }
    
    return (left == len);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        loop(i,0,n) cin >> arr[i];
        string s; cin >> s;
        
        if(canBreakIntoWords(s, arr, n)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}