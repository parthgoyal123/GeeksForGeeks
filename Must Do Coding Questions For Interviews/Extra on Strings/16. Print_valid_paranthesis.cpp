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
#define ALPHABET_SIZE 26

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

void printAllValidParanthesisUtil(char* pair, int curr_index, int n, int open, int close) {
    if(close == n) {
        pair[curr_index] = '\0';
        cout << pair << " ";
        return;
    }

    if(open > close) {
        pair[curr_index] = ')';
        printAllValidParanthesisUtil(pair, curr_index+1, n, open, close+1);
    }

    if(open < n) {
        pair[curr_index] = '(';
        printAllValidParanthesisUtil(pair, curr_index+1, n, open+1, close);
    }
}

void printAllValidParanthesis(int n) {
    char *pair = new char[2*n+1];

    printAllValidParanthesisUtil(pair, 0, n, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;

        printAllValidParanthesis(n);
    }
}