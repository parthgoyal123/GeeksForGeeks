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

int main(){
    int t;
    cin >> t;
    
    string temp;
    getline(cin, temp);
    while(t--){
        string str;
        getline(cin, str);
        
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        if (str[str.size()-1] != ' ') {
            str += ' ';    
        }
        
        int hard = 0;
        int easy = 0;
        
        int cons = 0;
        int vowels = 0;
        
        int consecutive_cons = 0;
        bool flag = false;
        
        loop(i, 0, str.size()) {
            if (str[i] == ' ') {
                if ((cons > vowels) || flag) {
                    hard++;
                } else {
                    easy++;
                }
                
                cons = 0, vowels = 0, consecutive_cons = 0, flag = false;
            } else if (str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u') {
                consecutive_cons = 0;
                vowels++;
            } else {
                cons++;
                consecutive_cons++;
                
                if(consecutive_cons == 4) {
                    flag = true;
                }
            }
        }
        
        cout << 5*hard+3*easy << endl;
    }
}