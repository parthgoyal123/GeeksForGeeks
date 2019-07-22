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

int longestValidParantheses(string &str) {

    int n = str.size();
    if(n == 1) return 0;
    
    stack<char> s;
    
    int max_length = 0;
    int left = -1;
    
    loop(i,0,n) {
        if(str[i] == '(') s.push(i);
        else {
            if(s.empty()) left = i;
            else {
                s.pop();
                
                if(s.empty()) {
                    max_length = max(max_length, i-left);
                } else {
                    max_length = max(max_length, i-s.top());
                }
            }
        }
    }
    
    return max_length;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        cout << longestValidParantheses(s) << endl;
    }
}