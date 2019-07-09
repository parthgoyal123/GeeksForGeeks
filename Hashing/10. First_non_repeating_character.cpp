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

char nonRepeating(string &s, int n) {
    int hash[26] = {0};
    
    loop(i,0,n) {
        hash[s[i]-'a']++;
    }
    
    loop(i,0,n){
        if(hash[s[i]-'a'] == 1) {
            return s[i];
        }
    }
    return '-';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        char c = nonRepeating(s,n);
        if (c == '-') cout << -1 << endl;
        else cout << c << endl;
    }
}