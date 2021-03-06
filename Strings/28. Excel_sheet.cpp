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

char getCharacter(int n) {
    if(n == 0) return 'Z';
    
    return (n-1) + 'A';
}

string columnTitle(int n) {
    string s;
    
    while(n > 0) {
        int mod = n%26;
        char character = getCharacter(mod); 
        s.pb(character);
        (n%26 == 0)? n = n/26-1: n = n/26;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = columnTitle(n);
        cout << s << endl;
    }
}