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

string recursive_duplicate(string str){
    int n = str.length();
    string temp;
    
    // check for duplicacy on leftmost
    if(str[0] != str[1]) {
        temp += str[0];
    }

    int i=1;
    while(i < n) {
        if(str[i] != str[i-1] && str[i] != str[i+1]) {
           temp += str[i];
            //cout<<"current temp string: "<<temp<<endl;
        }
        i++;
    }
    
    if(temp.length()==0) {
        return temp;
    }

    if(temp.length()!=str.length()) {
        return recursive_duplicate(temp);
    }

    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        s = recursive_duplicate(s);
        cout << s << endl;
    }
}