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

int getNumFromCharacter(char c) {
    return (c - 'A') + 1;
}

int getNumFromColumnTitle(string &s) {
    int num = 0;
    int n = s.size();
    loop(i, 0, n) {
        num = num*26 + getNumFromCharacter(s[i]);
    }
    return num;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        int num = getNumFromColumnTitle(s);
        cout << num << endl;
        
    }
}