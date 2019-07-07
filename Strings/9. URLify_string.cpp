#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define loopR(i,a,b) for(int i=a; i>=b; i--)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

inline void trim (string &str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

int main(){
    int t;
    cin >> t;
        
    while(t--){
        string temp;
        getline(cin, temp);
        
        string s;
        getline(cin, s);
        
        int k; 
        cin >> k;
        trim(s);
        
        int c = count(s.begin(), s.end(), ' ');
        
        int size_init = s.size();
        s.resize(s.size() + 2*c,  ' ');
        
        loopR(i, size_init-1, 0) {
            if(s[i] == ' ') {
                s[i + (2*c) - 2] = ' ';
                s[i + (2*c) - 1] = ' ';
                s[i + (2*c)] = ' ';
                c--;
            } else {
                s[i + 2*c] = s[i];
            }
        }
        
        // cout << s << endl;
        
        loop(i, 0, s.size()) {
            if (s[i] == ' '){
                s[i] = '%';
                s[i+1] = '2';
                s[i+2] = '0';
                i += 2;
            } 
        }
        
        cout << s << endl;
    }
}