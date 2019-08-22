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

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(string &str) {
    
    // use stack
    stack<int> st;
    
    // get length of the string
    int n = str.length();
    
    for(int i = 0; i<n; i++) {
        // check if operator or operand
        if(!isOperator(str[i])) {
            st.push(str[i] - '0');
        } 
        
        // if an operator, get operands and apply operator
        else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            // apply operation as per operator and push back in stack
            if(str[i] == '*') st.push(operand1 * operand2);
            else if (str[i] == '/') st.push(operand1 / operand2);
            else if (str[i] == '+') st.push(operand1 + operand2);
            else if (str[i] == '-') st.push(operand1 - operand2);
        }
    }
    
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string postfix;
        cin >> postfix;
        
        cout << evaluatePostfix(postfix) << endl;
    }
}