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

string removeAdjacentDuplicatesUtil(string s, char &prev) {
    int n = s.size();
    
    // cout << "start : " << s << endl;
    
    // base condition
    if(n == 0 || n == 1) return s;
    
    // check for leftmost duplicates
    if(s[0] == s[1]) {
        
        // define the prev removed
        prev = s[0];
        
        while(s[1] && s[0] == s[1]) s.erase(s.begin());
        
        // remove the last repeated
        s.erase(s.begin());
        
        // cout << "after removal : " << s << endl;
        
        // recur for rest string
        return removeAdjacentDuplicatesUtil(s, prev);
    }
    
    // leftmost not duplicates, therefore get for right n-1 length substring
    
    string front(1, s[0]);
    
    string temp = s.substr(1, n-1);
    
    string rem_str = removeAdjacentDuplicatesUtil(temp, prev);
    
    // cout << "front : " << front << "  ";
    // cout << "rem_str : " << rem_str << "  prev : " << prev << endl;
    
    // if first characters of right substring and original match
    if(rem_str[0] != '\0' && rem_str[0] == s[0]) {
        prev = rem_str[0];
        rem_str.erase(rem_str.begin());
        return rem_str;
    }
    
    // if rem_str is empty and last removed is equal to first character of original
    if(rem_str.empty() && s[0] == prev) return rem_str;
    if(rem_str.empty() && s[0] != prev) return front;
    
    // append the first character at starting
    rem_str = front + rem_str;
    
    // cout << "rem_str_final : " << rem_str << endl;
    
    return rem_str;
}

string removeAdjacentDuplicates(string &s) {

    // base condition
    char prev = '\0';
    int n = s.size();
    
    if(n == 0 || n == 1) return s;
    
    return removeAdjacentDuplicatesUtil(s, prev);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        
        s = removeAdjacentDuplicates(s);
        cout << s << endl;
    }
}