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

bool paranthesisChecker(string &s) {
    
    // check size of string.. should be even
    int n = s.size();
    
    if(n&1 == 1) return 0;
    
    stack<char> st;
    
    for(int i = 0; i<n; i++) {
        
        // if opening bracket, then push in stack
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        
        // if stack is empty, and not opening bracket, 'not balanced'
        if(st.empty()) return 0;
        
        // s[i] must be closing bracket, see conditions for it being wrong
        switch(s[i]) {
            case ')': {
                
                // get the bracket at the top of the stack and pop it
                char top = st.top();
                st.pop();
                
                if(top == '[' || top == '{') return 0;
                break;
            } case ']': {
                
                // get the bracket at the top of the stack and pop it
                char top = st.top();
                st.pop();
                
                if(top == '(' || top == '{') return 0;
                break;
            } case '}': {
                
                // get the bracket at the top of the stack and pop it
                char top = st.top();
                st.pop();
                
                if(top == '[' || top == '(') return 0;
                break;
            }
        }
    
    }
    
    // check for stack empty, if not empty then not balanced
    return (st.empty());
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        if(paranthesisChecker(s)) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
    }
}