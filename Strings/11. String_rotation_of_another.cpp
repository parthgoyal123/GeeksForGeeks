#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

bool rotated(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    if(n != m){
        return false;
    }
    
    if(s1 == s2){
        return true;
    }
    
    string cat = s1+s1;
    
    loop(i,0,n){
        string sub = cat.substr(i,n);
        if(sub == s2){
            return true;
        }
    }
    return false;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        
        if(rotated(s1, s2)){
            cout << 1;
        } else {
            cout << 0;
        } cout << endl;
    }
}