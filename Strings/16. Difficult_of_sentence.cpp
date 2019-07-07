#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    string temp;
    getline(cin, temp);
    while(t--){
        string s;
        getline(cin, s);
        
        int n = s.length();
        
        int consonants = 0;
        int vowels = 0;
        int continuous_cons = 0;
        int hard = 0;
        int easy = 0;
        
        int i = 0;
        
        for(i = 0; i<n; i++) {
            if(s[i] == ' ') {
                if (consonants > vowels) {
                    hard++;
                } else {
                    easy++;
                }
                
                consonants = 0;
                vowels = 0;
                continuous_cons = 0;
            } else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i') {
                vowels++;
                continuous_cons = 0;
            } else {
                consonants++;
                continuous_cons++;
                
                if(continuous_cons == 4) {
                    hard++;
                    consonants = 0;
                    vowels = 0;
                    continuous_cons = 0;
                    
                    while(i < n && s[i] != ' ') {
                        i++;
                    }
                    if(i == n){
                        i++;
                    }
                }
            }
        }
        
        if(i == n) {
            if(consonants > vowels) {
                hard++;
            } else {
                easy++;
            }
        }
        
        cout << 5*hard+3*easy << endl;
    }
}